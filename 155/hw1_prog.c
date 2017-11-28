// Attention, CS155 student!
//
// This is NOT the file that you want.
// The assignment said hw1_prog; this is hw1_prog.c.
// That .c at the end of the filename matters.
// You do NOT want this file.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // There are now TWO popes living there!
    printf("Vatican City has about %.2f popes per square km.\n", 2/0.44);
    printf("The best numbers are 21825, 1957, %u, and pi.\n",
	    getuid() * 65537);
    return 0;
}

// Since student user ids are allocated sequentially, two students may
// have uids that differ only by a single digit.  We don't want
// a student who makes an innocent typo to be accused of copying
// the work of another.
//
// Therefore, we multiply the uid by 65537.  This results in
// decimal numbers that are violently different.
