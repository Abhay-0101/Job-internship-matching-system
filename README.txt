JOB / INTERNSHIP MATCHING SYSTEM
================================

A console-based C project (DSA PBL) that matches a candidate's skills
with job or internship requirements and ranks the jobs from best match
to worst.


FEATURES
--------
- Add candidates with their skills
- Add jobs/internships with required skills
- View all candidates and jobs
- Find the best jobs for a chosen candidate, ranked by match percentage
- Save and load data automatically (data.txt)


HOW IT WORKS
------------
1. The user picks a candidate.
2. For every job, a match score is calculated:

   score = (required skills the candidate has / total required skills) x 100

3. The jobs are sorted from highest score to lowest.
4. The ranked list is printed.

Example output:

   Best matches for Abhay:
   1. Dev                       100% match
   2. Data                       50% match


DSA CONCEPTS USED
-----------------
- Arrays of structs : data.c  (storage of candidates and jobs)
- Linear search     : match.c (searching candidate skills)
- Bubble sort       : sort.c  (ranking results, descending)
- File handling     : file.c  (save/load data)


PROJECT STRUCTURE
-----------------
data.h    Shared structs, constants and function declarations
data.c    Storage, input and display of candidates and jobs
match.c   calcScore() using linear search
sort.c    sortResults() using bubble sort (highest score first)
file.c    saveData() and loadData()
main.c    Menu and integration of all modules
Makefile  Build instructions


TEAM CONTRIBUTION
-----------------
Person 1 : data.c          - arrays and structs (storage)
Person 2 : match.c         - searching
Person 3 : sort.c          - sorting
Person 4 : file.c, main.c  - file handling, menu, integration


BUILD AND RUN
-------------
Using make:

   make
   ./jobmatch

Using gcc directly (Windows PowerShell):

   gcc -Wall -o jobmatch main.c data.c match.c sort.c file.c
   .\jobmatch

To clean up build output and saved data:

   make clean


MENU
----
1. Add candidate
2. Add job/internship
3. Show candidates
4. Show jobs
5. Find best jobs for a candidate
6. Save data
0. Exit (also saves)


LIMITS AND NOTES
----------------
- Maximum 50 candidates and 50 jobs
- Maximum 5 skills per candidate or job
- Skills must be a single word (e.g. c, python, sql) and are stored
  in lowercase
- Names and titles are limited to 29 characters
- Data is stored in data.txt and loaded automatically at startup


COMPLEXITY
----------
- Scoring one job: O(s x s), where s is skills per entry (at most 5)
- Sorting: O(n^2) worst case, O(n) best case (early exit if sorted)


POSSIBLE IMPROVEMENTS
---------------------
- Replace bubble sort with merge sort or quick sort for large data
- Add input validation for all scanf calls
- Support multi-word skills
- Add delete and edit options for candidates and jobs
