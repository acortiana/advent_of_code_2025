#include <stdio.h>
#include <stdlib.h>

int is_digit(char a) {
    if (a >= '0' && a <= '9') { return 1; }
    return 0;
}

int is_eol(char a) {
    if (a == '\n' || a == 0) { return 1; }
    return 0;
}

int is_operator(char a) {
    if (a == '*' || a == '+' ) { return 1; }
    return 0;
}

int main() {
    char data[10][10000];
    for (int i=0; i < 10; i++) {
        for (int j=0; j < 10000; j++) {
            data[i][j] = 0;
        }
    }
    unsigned long int total = 0;
    int linecount;
    for (linecount = 0; fgets(data[linecount],10000,stdin) ; linecount++) { }
    int partials[10];
    int partials_start = 0;
    for (int j=0; j < 10; j++) { partials[j] = 0;}
    for (int i=0; ;i++) {
        int eolcount = 0;
        int spacecount = 0;
        char operator;
        for (int j=0; j < linecount; j++) {
            if (is_digit(data[j][i])) {
                partials[i-partials_start] = (partials[i-partials_start] * 10) + (data[j][i] - '0');
            } else if (is_operator(data[j][i])) {
                operator = data[j][i];
            } else if (is_eol(data[j][i])) {
                eolcount++;
            } else if (data[j][i] == ' ') {
                spacecount++;
            }
        }
        if ((eolcount == linecount) || (spacecount == linecount)) {
            unsigned long int result;
            if (operator == '*') {
                result = 1;
                for (int j = 0; j < 10; j++) { if (partials[j] != 0) { result *= (unsigned long int) partials[j]; } }
            } else {
                result = 0;
                for (int j = 0; j < 10; j++) { if (partials[j] != 0) { result += (unsigned long int) partials[j]; } }
            }
            total += result;
        }
        if (eolcount == linecount) { break; }
        if (spacecount == linecount) {
            partials_start=i+1;
            for (int j=0; j < 10; j++) { partials[j] = 0;}
        }
    }
    printf("%lu\n", total);
    return 0;
}