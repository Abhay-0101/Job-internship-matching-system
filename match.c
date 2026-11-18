/* match.c - Person 2: Searching (linear search) */
#include <string.h>
#include "data.h"

/* Returns % of the job's required skills that the candidate has (0-100).
   For each required skill, linearly search the candidate's skills. */
float calcScore(Candidate *c, Job *j) {
    if (j->skillCount == 0) return 0;

    int common = 0;
    for (int i = 0; i < j->skillCount; i++) {          /* each required skill */
        for (int k = 0; k < c->skillCount; k++) {      /* linear search */
            if (strcmp(j->skills[i], c->skills[k]) == 0) {
                common++;
                break;
            }
        }
    }
    return (common * 100.0f) / j->skillCount;
}
