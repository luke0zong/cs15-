
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    srand(time(NULL));

    for (int i = 1; i <= 5; i++)
        printf(" %d", 1 + rand() % 100);

    return 0;
}

