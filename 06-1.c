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
    char buffer[10000];
    unsigned long int data[10][1000];
    char operator[1000];
    unsigned long int total = 0;
    for (int line = 0; fgets(buffer,10000,stdin) ; line++) {
        char *tmp;
        tmp = buffer;
        while (1) {
            if (is_eol(*tmp) || is_digit(*tmp) || is_operator(*tmp)) { break; }
            tmp++;
        }
        if (is_eol(*tmp)) { break; }
        if (is_digit(*tmp)) {
            {
                int i=0;
                while (1) {
                    if (is_eol(*tmp)) { break;}
                    if (! is_digit(*tmp)) { tmp++; continue; }
                    data[line][i] = (int) strtol(tmp,NULL,10);
                    while (is_digit(*tmp)) {tmp++;}
                    i++;
                }
            }
        } else {
            {
                int i=0;
                while (1) {
                    if (is_eol(*tmp)) { break;}
                    if (! is_operator(*tmp)) { tmp++; continue; }
                    operator[i] = *tmp;
                    i++;
                    tmp++;
                }
                operator[i] = -1;
            }
            for (int i=0; operator[i] != -1; i++) {
                    unsigned long int result;
                    if (operator[i] == '*') {
                        result = 1;
                        for (int j = line -1; j >=0; j--) { result *= data[j][i]; }
                    } else {
                        result = 0;
                        for (int j = line -1; j >=0; j--) { result += data[j][i]; }
                    }
                    total += result;
            }
        }
    }
    printf("%lu\n",total);
}