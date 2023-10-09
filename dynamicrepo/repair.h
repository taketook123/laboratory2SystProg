#ifndef REPAIR_H
#define REPAIR_H

struct Repair {
    int break_code;
    char model_code[6];
    char description[100];
    char symptoms[100];
    char methods[100];
    char scrap_code_1[9];
    char scrap_code_2[9];
    char scrap_code_3[9];
    int price;
    int done;
};

void initializeRepair(struct Repair *repair);
void getRepairData(const struct Repair *repair);
void doRepair(struct Repair *repair);
int getBreakCode(const struct Repair *repair);

#endif // REPAIR_H
