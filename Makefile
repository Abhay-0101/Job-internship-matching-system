all:
	gcc -Wall -o jobmatch main.c data.c match.c sort.c file.c
clean:
	rm -f jobmatch data.txt
