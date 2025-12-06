#include <stdio.h>
#include <stdlib.h>


void main() {
    int counter = 0;
    int dial = 50;
    char buffer[100];
    while (fgets(buffer,100,stdin)) {
        int number = atoi(buffer+1);
        if (buffer[0] == 'L') {
            dial = (dial - number) % 100;
        } else {
            dial = (dial + number) % 100;
        }
        if (dial == 0) { counter++; }
    }
    printf("%d\n",counter);
}

