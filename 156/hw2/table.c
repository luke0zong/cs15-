/*
*
*CS156 Homework 2
*
*This program reads the dimensions of the table from the user,
*and then print the division table of the requested size.
*This will continue until dimensions that are both zero are given.
*
*By: Yaowei Zong (zongyw)
*03/10/2015
*
*/

#include <stdio.h>
int main()	{
	int W, H;								//Set two input variables.
	while (W >= 0 && H >= 0)	{			//While loop start.
		printf("Width & height? ");				//Read numbers from user.
		scanf("%d %d", &W, &H);

		if (W == 0 && H == 0)	{				//Set exit loop condition.
			printf("All done.\n");
			break;
		}

		else if (W >= 0 && H >= 0)	{			//Set division table output.
			int i, j;
			printf (" /");

			for (i = 1; i <= W; ++i)	{			//For loop 1: display width numbers.
				if ( i < 10 )	{						//Set spaces if number < 10.
					printf ("      %d", i);
				}
				else
					printf ("     %d", i);				//Set spaces if number >= 10.
			} 
			printf ("\n");

			for (j = 1; j <= H; ++j)	{			//For loop 2: display height numbers.
				if ( j < 10)	{						//Set spaces if number < 10.
					printf (" %d", j);
				}
				else
					printf ("%d", j);					//Set spaces if number >= 10.
					
				for (i = 1; i <= W; ++i)	{		//For loop 3: display division results.
					if ( i == j )	{					//Set spaces if division result is 1.000.
					    printf ("       ");
					}
					else if ( j/i > 9)
					    printf(" %.3f", j / ( i+0.0 ));		//Set spaces if division result >= 9.000.
					else
					    printf ("  %.3f", j / ( i+0.0 ));	//Set spaces if division result < 9.000.
				} 
				printf ("\n");
			}
				continue;
		}
		else
			printf("Please enter two positive numbers.\n");		//Set error message.
	}															//While loop ends.
	return 0;
}