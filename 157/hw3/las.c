/*
 *CS157 Homework 3
 *
 *The program’s purpose is to sort information in various ways
 *for members of the League of Attention-Seekers.
 *It take one or two arguments.
 *The first is a file containing information about the heroes.
 *The optional second argument is either “plain”, “super”, or “appear”.
 *
 *By: Yaowei Zong (zongyw)
 *04/27/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_NAME 30	// max size of the name of a hero
#define MAX_SIZE_LINE 80	// Total maximum size of a data file line
#define MAX_NUM_HEROES 100	// max number of heroes

// struct for hero info
typedef struct Hero {
	char plain[MAX_SIZE_NAME];
	char super[MAX_SIZE_NAME];
	int appear;
} Hero;

char *program_name;

// Function prototypes
int readHero(char filename[], Hero list[], int *count);
int compare_year(const void *year_a, const void *year_b);
int compare_plain(const void *plain_a, const void *plain_b);
int compare_super(const void *super_a, const void *super_b);
void printHero(Hero *h, int *header);
void usage();

int main(int argc, char *argv[])
{
	int count = 0;  // count for heroes numbers
	Hero heroes[MAX_NUM_HEROES];   // heroes array of struct Hero

	program_name = argv[0];	// get program name from the argument

	if (!(argc == 2 || argc == 3)) // correct argument numbers
		usage();

	if (readHero(argv[1], heroes, &count) != 0)    // test if readHero function succeed
		return 2;

	int header = 0;	// track for header print
	if (argc == 3) {
		// print in plain name order
		if (strcmp(argv[2], "plain") == 0) {
			qsort(heroes, count, sizeof(Hero), compare_plain);
			printHero(heroes, &header);
		}
		// print in super name order
		else if (strcmp(argv[2], "super") == 0) {
			qsort(heroes, count, sizeof(Hero), compare_super);
			printHero(heroes, &header);
		}
		// print in appear year order
		else if (strcmp(argv[2], "appear") == 0) {
			qsort(heroes, count, sizeof(Hero), compare_year);
			printHero(heroes, &header);
		}
		// invalid key complain
		else {
			fprintf(stderr, "Invalid sort key: %s.\n", argv[2]);
			usage();
		}
	}
	if (argc == 2) // default print format
		printHero(heroes, &header);
	return 0;
}

// --START-- Function Definition Zone

/*
 * Purpose: read lines from given file, and build the hero list
 * Input:   name of the file, list of all the heroes
 * Output:  return an error if could not open file, store the hero info in the array of heroes
 */
int readHero(char filename[], Hero list[], int *count)
{
	FILE *f = fopen(filename, "r");     // open file for reading
	if (f == NULL) {
		fprintf(stderr, "Can't open %s.\n", filename);
		usage();
		return 42;              // failure
	}
	char buf[MAX_SIZE_LINE]; //buffer for string line
	int i = 0;
	// store the hero info in the array list
	while (fgets(buf, sizeof(buf), f) != NULL)   {
		sscanf(buf, " %[^/]/%[^/]/%d\n", list[i].plain, list[i].super, &list[i].appear);
		i++;
	}
	*count = i;
	fclose(f); //  close file
	return 0;                   // success
}

/*
 * Purpose: compare by plain name order
 * Input:   two const void * pointers point to two hero plain names
 * Output:  return in alphabetical order
 */
int compare_plain(const void *plain_a, const void *plain_b) {
	const Hero *a = plain_a, *b = plain_b;
	return strcmp(a->plain, b->plain);
}

/*
 * Purpose: compare by super name order
 * Input:   two const void * pointers point to two hero super names
 * Output:  return in alphabetical order
 */
int compare_super(const void *super_a, const void *super_b) {
	const Hero *a = super_a, *b = super_b;
	return strcmp(a->super, b->super);
}

/*
 * Purpose: compare by appear year order
 * Input:   two const void * pointers point to two hero appear time
 * Output:  most recent comes first
 */
int compare_year(const void *year_a, const void *year_b) {
	const Hero *a = year_a, *b = year_b;
	if (a->appear > b->appear) return -1;
	if (a->appear < b->appear) return 1;
	return 0;
}

/*
 * Purpose: print the hero infomation in required format
 * Input:   pointer to struct, pointer to header track
 * Output:  print result
 */
void printHero(Hero *h, int *header)
{
	//int header = 0;    // track of print header
	if (*header != 1)
	{
		printf("%-30s %-30s %s\n", "Plain", "Super", "Appear");
		printf("%-30s %-30s %s\n", "~~~~~", "~~~~~", "~~~~~.");
		*header = 1;
	}
	for (int i = 0; i < 6; i++)
		printf("%-30s %-30s %d\n", h[i].plain, h[i].super, h[i].appear);
	return;
}
/*
 * Purpose: print the usage message
 * Input:   none
 * Output:  error message to standard error
 */
void usage() {
	fprintf(stderr, "Usage: %s file [plain|super|appear]\n", program_name);
	exit(1);
}