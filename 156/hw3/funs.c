/*
 *
 *CS156 Homework 3
 *
 *This program does two things,
 *convert temperatures to a descriptive letter
 *and summarize an amendment to the U.S. Constitution
 *
 *By: Yaowei Zong (zongyw)
 *03/24/2015
 *
 */

#include <stdio.h>

// Function prototypes
void print_menu();							// Print the help menu
void bill_of_rights(int amendment);			// Print the amendment summary for this amendment.
char temp_to_letter(double temperature);	// Return letter describing this temperature

int main()	{
	char cmd;	// character variable 'cmd'(short for command) declared.
	printf( "CS156 puts the \"shun\" in \"function\"!\n" );

	// Start for loop.
	for (;;) {
		printf( "Do what? " );
		scanf( "%c%*c", &cmd );		// read single-character command and dump the enter key
		// switch conditions for cmd
		switch (cmd) {
		default :	printf( "Invalid command '%c'; 'h' for help.\n", cmd );	continue;
		// case h as help
		case 'h':	print_menu();	continue;	// call function print_menu
		// case a as amendment
		case 'a':	{
			int num;	// integer variable 'num'(short for number) declared.
			printf("Which amendment? ");
			scanf( "%d%*c", &num );		// read number of amendment and dump the enter key
			printf("Amendment #%d is ", num);
			bill_of_rights(num);		// call function bill_of_rights
		}
		continue;
		// case t as temperature
		case 't':	{
			double temp;	// double variable 'temp'(short for temperature) declared.
			printf("What temperature? ");
			scanf( "%lf%*c", &temp );	// read temperature and dump the enter key
			printf("%.1f is %c\n", temp, temp_to_letter(temp) );	// call function temp_to_letter
		}
		continue;
		// case q as quit
		case 'q':	return 0;	break;	// define escape of loop condition
		}
	}
	// End for loop.
	return 0;
}

// --START-- Function Definition Zone

// Print the help menu
void print_menu() {
	printf("q - quit\n");
	printf("h - help\n");
	printf("a - display a one-word summary of the given amendment\n");
	printf("t - translate a temperature to a feeling\n");
}
// End of function print_menu

/*
 * Purpose: print one-word summary of the United States Bill of Rights.
 * Input:	integer variable amendment using in switch conditions.
 * Output:	print the amendment summary for this amendment.
 */
void bill_of_rights(int amendment) {
	switch (amendment) {
	case 1 : printf("expression\n");	break;
	case 2 : printf("arms\n");			break;
	case 3 : printf("quartering\n");	break;
	case 4 : printf("search\n");		break;
	case 5 : printf("process\n");		break;
	case 6 : printf("speedy\n");		break;
	case 7 : printf("jury\n");			break;
	case 8 : printf("bail\n");			break;
	case 9 : printf("other\n");			break;
	case 10: printf("states\n");		break;
	default: printf("UNKNOWN\n");		break;
	}
}
// End of function bill_of_rights

/*
 * Purpose: convert temperatures to a descriptive letter.
 * Input:	double variable temperature using in if conditions.
 * Output:	return the single-letter character descriptions for this temperature.
 */
char temp_to_letter(double temperature) {
	if	(temperature >= 212)
		return 'B';
	else if	(temperature >= 100)
		return 'H';
	else if	(temperature >= 70)
		return 'W';
	else if	(temperature >= 50)
		return 'N';
	else if	(temperature >= 32)
		return 'C';
	else
		return 'F';
}
// End of function temp_to_letter

// --END-- Function Definition Zone