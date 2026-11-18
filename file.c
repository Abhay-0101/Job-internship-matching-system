/* file.c - Person 4: File handling (save/load) */
#include <stdio.h>
#include "data.h"

void saveData(const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) { printf("Could not open file for saving.\n"); return; }

    fprintf(f, "%d\n", candidateCount);
    for (int i = 0; i < candidateCount; i++) {
        fprintf(f, "%s\n%d", candidates[i].name, candidates[i].skillCount);
        for (int k = 0; k < candidates[i].skillCount; k++)
            fprintf(f, " %s", candidates[i].skills[k]);
        fprintf(f, "\n");
    }

    fprintf(f, "%d\n", jobCount);
    for (int i = 0; i < jobCount; i++) {
        fprintf(f, "%s\n%d", jobs[i].title, jobs[i].skillCount);
        for (int k = 0; k < jobs[i].skillCount; k++)
            fprintf(f, " %s", jobs[i].skills[k]);
        fprintf(f, "\n");
    }
    fclose(f);
    printf("Data saved to %s\n", filename);
}

void loadData(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return;   /* no file yet: start empty */

    if (fscanf(f, "%d", &candidateCount) != 1) candidateCount = 0;
    for (int i = 0; i < candidateCount; i++) {
        fscanf(f, " %29[^\n]", candidates[i].name);
        fscanf(f, "%d", &candidates[i].skillCount);
        for (int k = 0; k < candidates[i].skillCount; k++)
            fscanf(f, "%29s", candidates[i].skills[k]);
    }

    if (fscanf(f, "%d", &jobCount) != 1) jobCount = 0;
    for (int i = 0; i < jobCount; i++) {
        fscanf(f, " %29[^\n]", jobs[i].title);
        fscanf(f, "%d", &jobs[i].skillCount);
        for (int k = 0; k < jobs[i].skillCount; k++)
            fscanf(f, "%29s", jobs[i].skills[k]);
    }
    fclose(f);
    printf("Loaded %d candidates and %d jobs.\n", candidateCount, jobCount);
}
