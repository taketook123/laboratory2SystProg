#include <stdio.h>
#include <string.h>
#include "repair.h"

void initializeRepair(struct Repair *repair) {
    printf("Type code of break (from 100 to 600): ");
    scanf("%d", &(repair->break_code));
    printf("Type code of model (5 symbols): ");
    scanf("%5s", repair->model_code);
    printf("Type description: ");
    scanf(" %[^\n]", repair->description);
    printf("Type symptoms: ");
    scanf(" %[^\n]", repair->symptoms);
    printf("Type fix method: ");
    scanf(" %[^\n]", repair->methods);
    printf("Enter 1st detail serial number (8 numbers): ");
    scanf("%8s", repair->scrap_code_1);
    printf("Enter 2nd detail serial number (8 numbers): ");
    scanf("%8s", repair->scrap_code_2);
    printf("Enter 3rd detail serial number (8 numbers): ");
    scanf("%8s", repair->scrap_code_3);
    printf("Enter repair price: ");
    scanf("%d", &(repair->price));
    repair->done = 0;
}

void getRepairData(const struct Repair *repair) {
    printf("Model: %s. Break code: %d. Description: %s. Price: %d. ", repair->model_code, repair->break_code, repair->description, repair->price);
    if (repair->done) {
        printf("Done: Yes");
    } else {
        printf("Done: No");
    }
    printf("\n");
}

void doRepair(struct Repair *repair) {
    repair->done = 1;
}

int getBreakCode(const struct Repair *repair) {
    return repair->break_code;
}