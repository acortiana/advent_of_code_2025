#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_SIZE 10000

char *itoa(unsigned long int a) {
    char string[30];
    char *string_reverse;
    char *string_reverse_ptr; 
    string_reverse = malloc(30);
    string_reverse_ptr = string_reverse;

    char *strptr = string;
    for (unsigned long int i = 1; (a / i) > 0 ; i *= 10) {
        *strptr = ((a / i) % 10) + '0';
        strptr++;
    }
    strptr--;
    while (strptr >= string) {
        *string_reverse_ptr = *strptr;
        string_reverse_ptr++;
        strptr--;
    }
    *string_reverse_ptr = '\0';
    return string_reverse;
}

int str_symmetry(char *a) {
    int len = strlen(a);
    if (len % 2) { return 0; }
    int halflen = len / 2;
    for (int i = 0; i < halflen; i++) {
        if (a[i] != a[i+halflen]) { return 0;}
    }
    return 1;
}

unsigned long int process(char *a, char *b) {
    unsigned long int invalid_sum = 0;
    unsigned long int start = (unsigned long int) strtol(a,NULL,10);
    unsigned long int end = (unsigned long int) strtol(b,NULL,10);
    for (unsigned long int i = start; i <= end; i++) {
        char *tmp = itoa(i);
        if (str_symmetry(tmp)) { invalid_sum += i; }
        free(tmp);
    }
    return invalid_sum;
}


int main() {
    char *string = malloc(MAX_STRING_SIZE);
    fgets(string,MAX_STRING_SIZE,stdin);
    char *strptr = string;
    unsigned long int invalid_sum = 0;
    while (1) {
        char buf1[100];
        char buf2[100];
        for (int i=0; *strptr >= '0' && *strptr <= '9'; i++) {
            buf1[i] = *strptr;
            buf1[i+1] = 0;
            strptr++;
        }
        strptr++;
        for (int i=0; *strptr >= '0' && *strptr <= '9'; i++) {
            buf2[i] = *strptr;
            buf2[i+1] = 0;
            strptr++;
        }
        invalid_sum += process(buf1,buf2);
        if (*strptr == '\n' || *strptr == '\0') {
            break;
        } else {
            strptr++;
        }
    }
    free(string);
    printf("%lu\n",invalid_sum);
}

