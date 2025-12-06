#include <stdio.h>
#include <stdlib.h>

struct range {
    long unsigned int start;
    long unsigned int end;
};

struct range get_range(char *a) {
    struct range aa;
    char *tmp;
    aa.start = (long unsigned int) strtol(a,&tmp,10);
    aa.end = (long unsigned int) strtol(tmp+1,NULL,10);
    return aa;
}

void main() {
    char buffer[200];
    struct range ranges[500];
    int total = 0;
    for (int i=0; fgets(buffer,200,stdin); i++){
        ranges[i].start = 0;
        ranges[i].end = 0;
        if (buffer[0] == '\n') { break; }
        ranges[i] = get_range(buffer);
    }
    while (fgets(buffer,200,stdin)) {
        long unsigned int mynum = (long unsigned int) strtol(buffer,NULL,10);
        for (int i=0; ranges[i].end != 0; i++) {
            if ((mynum >= ranges[i].start) && (mynum <= ranges[i].end)) {
                total++;
                break;
            }
        }
    }
    printf("%d\n",total);
}