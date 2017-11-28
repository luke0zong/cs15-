#include "mod.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
        initialize();
	for(int i=1; i<=argc-1; i++)
	{
	    printf("readfile returned = %d\n", readfile(argv[i]));
	}
	
        //readfile("test1.data");
	//readfile("test2.data");
        printf("How many: %d\n", count());
        printf(" Largest: %d.\n", largest());
        printf("   Total: %d.\n", total());
	terminate();
	return 0;
}
