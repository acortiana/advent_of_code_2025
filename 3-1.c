#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIGIT_COUNT 2


long unsigned int powten(int exp) {
    long unsigned int result = 1;
    if (exp == 0) { return 1; }
    for (int i=1; i <= exp; i++) {
        result *= 10;
    }
    return result;
}

void main() {
    char buffer[150];
    long unsigned int total = 0;
    while (fgets(buffer,150,stdin)) {
	int len = 0;
	for (int i=0; buffer[i] != 0; i++) {
            if ((buffer[i] >= '0') && (buffer[i] <= '9')) { len++; continue; }
	    buffer[i] = 0;
	    break;
	}
	char digits[DIGIT_COUNT];
	for (int i=0; i < DIGIT_COUNT; i++) { digits[i] = 0; }
        int delim = 0;
	for (int i=0; i < DIGIT_COUNT; i++) {
            for (int j=delim; j < (len-(DIGIT_COUNT-(i+1))); j++) {
                char digit = buffer[j] - '0';
                if (digit > digits[i]) {
                    digits[i] = digit;
                    delim = j+1;
                }
            }
	}
	long unsigned int partial = 0;
        long unsigned int multiplier = 1;
	for (int i=0; i < DIGIT_COUNT; i++) {
            partial += (long unsigned int) digits[i] * powten(DIGIT_COUNT-(i+1));
	}
        total += partial;
    }
    printf("%lu\n",total);
}

