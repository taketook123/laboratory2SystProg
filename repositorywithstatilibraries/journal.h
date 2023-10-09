#ifndef JOURNAL_H
#define JOURNAL_H

#define MAX_RECORDS 100

struct Note {
    char type; // бере тільки a, m
    int break_code;
    
};


void addRecord(struct Note list[], int* count, char type, int break_code);
void getRecordData(const struct Note* note);

#endif // JOURNAL_H