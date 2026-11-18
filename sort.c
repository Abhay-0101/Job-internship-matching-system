/* sort.c - Person 3: Sorting (bubble sort, highest score first) */
#include "data.h"

void sortResults(Result r[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (r[j].score < r[j + 1].score) {   /* descending order */
                Result temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;   /* already sorted */
    }
}
