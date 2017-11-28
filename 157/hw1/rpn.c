/*
 *
 *CS157 Homework 1
 *
 *This program is a RPN calculator
 *It recognize numbers in various bases,
 *and also emit the answer in various bases.
 *usage: [program name] [H|O|D] <left> <right> <operator>
 *
 *By: Yaowei Zong (zongyw)
 *04/13/2015
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int calc(char oper[], long left, long right, int *err);	// calculate based on operator
void result_base(char base[], int result, int *err);	// print result on given base

int main(int argc, char *argv[]) {

	int  result, err = 0;	// integer result and err checking
	long num1, num2;		// long int for two numbers
	char operat[2], base[2];// operator and output base type

	// error message when too many or too few arguments
	if (argc != 4 && argc != 5)	{
		fprintf(stderr, "usage: %s [H|O|D] <left> <right> <operator>\n", argv[0]);
		return 1;
	}

	// get base type, numbers and operator
	if (argc == 4)	{
		// assign num from command line arguments
		num1 = strtol(argv[1], NULL, 0);
		num2 = strtol(argv[2], NULL, 0);
		// copy operator from command line arguments
		strcpy(operat, argv[3]);
		// call calc function to calculate
		result = calc(operat, num1, num2, &err);
		// call secult_base function to print result
		if (err == 2) {
			fprintf(stderr, "Don't divided by zero!\nusage: %s [H|O|D] <left> <right> <operator>\n", argv[0]);
			return 2;
		}
		if (err == 0)
			result_base("D", result, &err);
		// print error message: usage
		if (err == 1) {
			fprintf(stderr, "usage: %s [H|O|D] <left> <right> <operator>\n", argv[0]);
			return 3;
		}
	}

	if (argc == 5)	{
		// assign num from command line arguments
		num1 = strtol(argv[2], NULL, 0);
		num2 = strtol(argv[3], NULL, 0);
		// copy base and operator from command line arguments
		strcpy(base, argv[1]);
		strcpy(operat, argv[4]);
		// call calc function to calculate
		result = calc(operat, num1, num2, &err);
		// call secult_base function to print result
		if (err == 2) {
			fprintf(stderr, "Don't divided by zero!\nusage: %s [H|O|D] <left> <right> <operator>\n", argv[0]);
			return 2;
		}
		if (err == 0)
			result_base(base, result, &err);
		// print error message: usage
		if (err == 1) {
			fprintf(stderr, "usage: %s [H|O|D] <left> <right> <operator>\n", argv[0]);
			return 3;
		}
	}
	return 0;
}

// --START-- Function Definition Zone

/*
 * Purpose: calculate result based on operator.
 * Input:	string operator, two long int numbers, pointer to int err message.
 * Output:	return the integer result based on operator.
 */
int calc(char oper[], long left, long right, int *err)	{
	int result;
	if (strcmp(oper, "+") == 0)
		result = left + right;
	else if (strcmp(oper, "-") == 0)
		result = left - right;
	else if (strcmp(oper, "*") == 0)
		result = left * right;
	else if (strcmp(oper, "/") == 0) {
		if (right == 0)
			return *err = 2;	// handle divided by zero situation
		else result = left / right;
	}
	else if (strcmp(oper, ",") == 0)
		result = abs(left - right);
	else	{
		*err = 1;
		return *err;
	}
	return result;

}
// End of function calc

/*
 * Purpose: print result based on base type.
 * Input:	string base type, integer result, pointer to int error message.
 * Output:	various based result.
 */
void result_base(char base[], int result, int *err) {
	if (strcmp(base, "H") == 0) {
		if (result < 0) {
			printf("-%x\n", abs(result));
		}
		else printf("%x\n", result);
	}
	else if (strcmp(base, "O") == 0) {
		if (result < 0) {
			printf("-%o\n", abs(result));
		}
		else printf("%o\n", result);
	}
	else if (strcmp(base, "D") == 0)
		printf("%d\n", result);
	else *err = 1;
}
// End of function result_base

// --END-- Function Definition Zone