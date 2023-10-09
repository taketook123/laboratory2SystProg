#include <stdio.h>
#include "journal.h"

void addRecord(struct Note list[], int* count, char type, int break_code) {
    if (*count < MAX_RECORDS) {
        list[*count].type = type;
        list[*count].break_code = break_code;
        (*count)++;
    } else {
        fprintf(stderr, "The list is full. Cannot add more records.\n");
    }
}

void getRecordData(const struct Note* note) {
    if (note->type == 'a') {
        printf("Type: Add");
    } else {
        printf("Type: Do");
    }
    printf(". Code: %d\n", note->break_code);
}