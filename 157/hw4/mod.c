/*
 *CS157 Homework 4
 *
 *This program is a module used by another program
 *It uses dynamic memory to store numbers and compute simple statistics.
 *
 *By: Yaowei Zong (zongyw)
 *05/06/2015
 */
#include "mod.h"
#include <stdio.h>
#include <stdlib.h>

// define linked list LIST
typedef struct node_struct
{
	int value;
	struct node_struct *next;
} LIST;

// define head, current and temp node
LIST *head, *current, *tmp;

int index = 0;
int num, sum, large;
int control, initial = 0;

// read ints from a file, stores them into dynamically-allocated memory
int readfile(const char *filename) {
	// check if called initialize function first
	if (initial != 1) {
		fprintf(stderr, "Please initialize first!\n");
		return 1;
	}
	FILE *f = fopen(filename, "r");
	// faild open file
	if (f == NULL) {
		fprintf(stderr, "Can open file <%s>\n", filename);
		return 2;
	}
	// read ints from file
	while ( (control = (fscanf(f, "%d", &num))) != EOF ) {
		// read int success
		if (control == 1) {
			tmp = malloc(sizeof(LIST));	// memory allocation
			if (tmp == NULL) {     // check if allocation success
				printf("Failed to allocate memory\n");
				return 42;
			}
			tmp->next = NULL;	// point next to NULL
			tmp->value = num;	// set int into node
			if (head == NULL) {
				current = head = tmp;	// point head to first node
			}
			else {
				current = current->next = tmp; // move to next node
			}
			index++;	// count for all ints
		}
		// encountering non-integer data, complain and exit
		else {
			fprintf(stderr, "Non-integer data in <%s>!\n", filename );
			return 3;
		}
	}
	fclose(f); // close file
	return 0;	// readfile succeed
}

// returns how many numbers have been read, from all files.
int count() {
	return index;
}

// returns the total of all the numbers read, from all files.
int total() {
	for (current = head; current; current = current->next) {
		sum += current->value;
	}
	return sum;
}

// returns the largest number read, from all files.
int largest() {
	large = head->value;
	for (current = head; current; current = current->next) {
		if ( !(current->value < large) ) {
			large = current->value;
		}
	}
	return large;
}

// called before anything else, initialize the head pointer
void initialize() {
	head = current = NULL;
	initial = 1;
}

// called after everything else, free all memory allocated
void terminate() {
	free(tmp);
	free(head);
	free(current);
}