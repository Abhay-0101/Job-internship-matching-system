/* data.c - Person 1: Arrays + structs (storage) */
#include <stdio.h>
#include <ctype.h>
#include "data.h"

Candidate candidates[MAX_CANDIDATES];
Job       jobs[MAX_JOBS];
int       candidateCount = 0;
int       jobCount = 0;

/* convert a word to lowercase so "C" and "c" match */
static void toLower(char *s) {
    for (; *s; s++) *s = tolower((unsigned char)*s);
}

/* read up to MAX_SKILLS skills (single words) */
static int readSkills(char skills[][STR_LEN]) {
    int n;
    do {
        printf("How many skills (1-%d)? ", MAX_SKILLS);
        if (scanf("%d", &n) != 1) { while (getchar() != '\n'); n = 0; }
    } while (n < 1 || n > MAX_SKILLS);

    for (int i = 0; i < n; i++) {
        printf("  Skill %d (one word, e.g. c, python, sql): ", i + 1);
        scanf("%29s", skills[i]);
        toLower(skills[i]);
    }
    return n;
}

void addCandidate(void) {
    if (candidateCount >= MAX_CANDIDATES) { printf("Candidate list full!\n"); return; }
    Candidate *c = &candidates[candidateCount];
    printf("Candidate name: ");
    scanf(" %29[^\n]", c->name);
    c->skillCount = readSkills(c->skills);
    candidateCount++;
    printf("Candidate added.\n");
}

void addJob(void) {
    if (jobCount >= MAX_JOBS) { printf("Job list full!\n"); return; }
    Job *j = &jobs[jobCount];
    printf("Job/Internship title: ");
    scanf(" %29[^\n]", j->title);
    printf("Enter REQUIRED skills.\n");
    j->skillCount = readSkills(j->skills);
    jobCount++;
    printf("Job added.\n");
}

void displayCandidates(void) {
    if (candidateCount == 0) { printf("No candidates yet.\n"); return; }
    printf("\n--- Candidates ---\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s | skills:", i + 1, candidates[i].name);
        for (int k = 0; k < candidates[i].skillCount; k++)
            printf(" %s", candidates[i].skills[k]);
        printf("\n");
    }
}

void displayJobs(void) {
    if (jobCount == 0) { printf("No jobs yet.\n"); return; }
    printf("\n--- Jobs ---\n");
    for (int i = 0; i < jobCount; i++) {
        printf("%d. %s | requires:", i + 1, jobs[i].title);
        for (int k = 0; k < jobs[i].skillCount; k++)
            printf(" %s", jobs[i].skills[k]);
        printf("\n");
    }
}
