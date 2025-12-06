#include <stdio.h>
#include <stdlib.h>


void main() {
    int counter = 0;
    int dial = 50;
    char buffer[100];
    while (fgets(buffer,100,stdin)) {
        int number = atoi(buffer+1);
        counter = counter + (number / 100);
        number = number - ((number / 100) * 100);
        if (buffer[0] == 'L') {
            if ((dial > 0) && ((dial - number) <= 0)) { counter++;}
            dial = (dial - number) % 100;
            if (dial < 0) { dial += 100; }
        } else {
            if ((dial + number) >= 100) { counter++;}
            dial = (dial + number) % 100;
        }
    }
    printf("%d\n",counter);
}

