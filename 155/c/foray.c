#include <stdio.h>


int main() {
   int miles;
  int *ptrMiles;
  ptrMiles = &miles;		// Note: * not used when setting ptr's contents
  *ptrMiles = 45;			//   * IS used when setting contents of where ptr points to
  printf( "Location of miles: %p\n", &miles );			// needs &
  printf( "Location of ptrMiles: %p\n", ptrMiles );		// no needs &

    return 0;
}

