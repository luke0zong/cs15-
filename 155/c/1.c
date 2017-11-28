#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int*    x;  // Allocate the pointers x and y
    int*    y;  // (but not the pointees)
    
    x = malloc(sizeof(int));    // Allocate an int pointee,
                                // and set x to point to it
    
    *x = 42;    // Dereference x to store 42 in its pointee
	printf("x=%d", *x);
       
    y = x;      // Pointer assignment sets y to point to x's pointee
    
    *y = 13;    // Dereference y to store 13 in its (shared) pointee
	printf("y=%d", *y);
    return 0;
}