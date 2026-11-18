/* main.c - Person 4: menu + integration */
#include <stdio.h>
#include "data.h"

#define DATA_FILE "data.txt"

static void showBestJobs(void) {
    if (candidateCount == 0 || jobCount == 0) {
        printf("Add at least one candidate and one job first.\n");
        return;
    }
    displayCandidates();
    int choice;
    printf("Choose candidate number: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > candidateCount) { printf("Invalid choice.\n"); return; }

    Candidate *c = &candidates[choice - 1];
    Result results[MAX_JOBS];

    for (int i = 0; i < jobCount; i++) {
        results[i].jobIndex = i;
        results[i].score = calcScore(c, &jobs[i]);   /* Person 2 */
    }
    sortResults(results, jobCount);                   /* Person 3 */

    printf("\nBest matches for %s:\n", c->name);
    for (int i = 0; i < jobCount; i++)
        printf("%d. %-25s %.0f%% match\n",
               i + 1, jobs[results[i].jobIndex].title, results[i].score);
}

int main(void) {
    int choice;
    loadData(DATA_FILE);

    do {
        printf("\n===== Job/Internship Matching System =====\n");
        printf("1. Add candidate\n2. Add job/internship\n");
        printf("3. Show candidates\n4. Show jobs\n");
        printf("5. Find best jobs for a candidate\n6. Save data\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) { while (getchar() != '\n'); choice = -1; }

        switch (choice) {
            case 1: addCandidate(); break;
            case 2: addJob(); break;
            case 3: displayCandidates(); break;
            case 4: displayJobs(); break;
            case 5: showBestJobs(); break;
            case 6: saveData(DATA_FILE); break;
            case 0: saveData(DATA_FILE); printf("Bye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
