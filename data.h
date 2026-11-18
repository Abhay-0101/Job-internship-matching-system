/* data.h - SHARED by all 4 members. Agree on this first! */
#ifndef DATA_H
#define DATA_H

#define MAX_CANDIDATES 50
#define MAX_JOBS       50
#define MAX_SKILLS     5
#define STR_LEN        30

typedef struct {
    char name[STR_LEN];
    char skills[MAX_SKILLS][STR_LEN];
    int  skillCount;
} Candidate;

typedef struct {
    char title[STR_LEN];
    char skills[MAX_SKILLS][STR_LEN];
    int  skillCount;
} Job;

/* One matching result: which job and its score */
typedef struct {
    int   jobIndex;
    float score;
} Result;

/* Global arrays (defined in data.c) */
extern Candidate candidates[MAX_CANDIDATES];
extern Job       jobs[MAX_JOBS];
extern int       candidateCount;
extern int       jobCount;

/* Person 1: data.c */
void addCandidate(void);
void addJob(void);
void displayCandidates(void);
void displayJobs(void);

/* Person 2: match.c */
float calcScore(Candidate *c, Job *j);

/* Person 3: sort.c */
void sortResults(Result r[], int n);

/* Person 4: file.c */
void saveData(const char *filename);
void loadData(const char *filename);

#endif
