#include <stdio.h>
#include <dlfcn.h> // Заголовочный файл для работы с динамическими библиотеками
#include "repair.h"
#include "journal.h"

int main() {
    // Імпортуємо бібліотеки
    void *lib_handle = dlopen("./librepair.so", RTLD_LAZY);
    void *lib_journal = dlopen("./libjournal.so", RTLD_LAZY);
    if (!lib_journal || !lib_handle) {
        fprintf(stderr, "Error loading libraries: %s\n", dlerror());
        return 1;
    }

    // Определяем указатели на функции из першої бібліотеки
    void (*initializeRepair)(struct Repair *) = dlsym(lib_handle, "initializeRepair");
    void (*getRepairData)(const struct Repair *) = dlsym(lib_handle, "getRepairData");
    void (*doRepair)(struct Repair *) = dlsym(lib_handle, "doRepair");
    int (*getBreakCode)(const struct Repair *) = dlsym(lib_handle, "getBreakCode");

    void (*addRecord)(struct Note *, int *, char, int) = dlsym(lib_journal, "addRecord");
    void (*getRecordData)(const struct Note*) = dlsym(lib_journal, "getRecordData");

    if (!initializeRepair || !getRepairData || !doRepair || !getBreakCode || !addRecord || !getRecordData) {
        fprintf(stderr, "Error loading symbols: %s\n", dlerror());
        dlclose(lib_handle);
        dlclose(lib_journal);
        return 1;
    }


    // Тут ми використовуємо ці функції з бібліотеки
    struct Repair repairList[10];
    struct Note recordList[MAX_RECORDS]; //
    char choice;
    int count = 0;
    int count_notes = 0;

    while (1) {
        printf("What would you like to do?\n");
        printf("a) Add a Repair object\n");
        printf("t) See all repairs\n");
        printf("d) Mark repair as done\n");
        printf("h) See history of work\n");
        printf("q) Quit\n");
        printf("---> ");
        scanf(" %c", &choice);
        if (choice == 'q') {
            break; // Завершаем программу при вводе 'q'
        } else if (choice == 'a') {
            if (count < 5) {
                // Инициализируем новый объект данными
                initializeRepair(&repairList[count]);

                // Выводим данные объекта
                printf("Data for the newly created Repair object:\n");
                getRepairData(&repairList[count]);
                addRecord(recordList, &count_notes, 'a', getBreakCode(&repairList[count])); // дод запису
                count++; // Увеличиваем счетчик объектов
            } else {
                printf("The list is full. Cannot add more Repair objects.\n");
            }
            

        } else if (choice == 'd') {
            int breakCode;
            printf("Enter break code to mark repair as done: ");
            scanf("%d", &breakCode);

            // Ищем объект с указанным break_code и выполняем функцию doRepair
            for (int i = 0; i < count; i++) {
                if (repairList[i].break_code == breakCode) {
                    doRepair(&repairList[i]);
                    printf("Repair with break code %d marked as done.\n", breakCode);
                    addRecord(recordList, &count_notes, 'a', getBreakCode(&repairList[count])); // дод запису
                    break; // Прерываем цикл после выполнения
                }
            }
        } else if (choice == 't') {
            printf("Our Table is\n============================\n");
            for (int i = 0; i < count; i++) {
                getRepairData(&repairList[i]);
            }
            printf("============================\n");
        } else if (choice == 'h') {
            printf("Hisory of work\n============================\n");
            for (int i = 0; i < count; i++) {
                getRecordData(&recordList[i]);
            }
            printf("============================\n");            
        } else {
            printf("Invalid input. Please enter 'a', 'm', or 'q'.\n");
        }
    }

    dlclose(lib_handle);
    dlclose(lib_journal);

    return 0;
}
