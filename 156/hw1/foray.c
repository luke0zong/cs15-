/*
*
*CS156 Homework 1
*
*This program reads two numbers from the user,
*and produces a few arguably-interesting facts about the numbers
*
*By: Yaowei Zong (zongyw)
*03/04/2015
*
*/

#include <stdio.h>
int main() {
	//num1 and num2 declared as integer variables.
	int num1, num2;
	//Get input from user.
	printf( "Enter the two numbers: " );
	scanf( "%d%d", &num1, &num2 );
	//Display the result of dividing the first number by the second one, using floating-point division.
	//Using (double) before num1 / num2 converse int to double.
	if (num2 == 0)
		printf( "Dividing %d by %d gives us problems.\n", num1, num2 );
	else
		printf( "Dividing %d by %d gives us %f.\n", num1, num2, (double) num1 / num2 );
	//Display the positive difference of the two numbers.
	if (num1 > num2)
		printf( "The difference is %d.\n", num1 - num2 );
	else
		printf( "The difference is %d.\n", num2 - num1 );
	//Display which number is bigger, or if they’re equal.
	if (num1 == num2)
		printf( "%d and %d are equal.\n", num1, num2 );
	if (num1 > num2)
		printf( "%d is larger.\n", num1 );
	if (num1 < num2)
		printf( "%d is larger.\n", num2 );
	//Display which numbers are evenly divisible by seven
	if ( num1 % 7 == 0 && num2 % 7 == 0 )
		printf( "Both are divisible by seven.\n");
	if ( num1 % 7 != 0 && num2 % 7 != 0 )
		printf( "Neither are divisible by seven.\n");
	if ( num1 % 7 == 0 && num2 % 7 != 0 )
		printf( "Only %d is divisible by seven.\n", num1 );
	if ( num1 % 7 != 0 && num2 % 7 == 0 )
		printf( "Only %d is divisible by seven.\n", num2 );
	return 0;
}