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

int intersect(struct range a, struct range b) {
    if (a.start > b.end) { return 0;}
    if (b.start > a.end) { return 0;}
    return 1;
}

struct range get_result_range(struct range a, struct range b) {
    struct range result;
    if ((b.start >= a.start) && (b.start <= a.end)) { result.start = a.start; }
    if ((a.start >= b.start) && (a.start <= b.end)) { result.start = b.start; }
    if ((b.end <= a.end) && (b.end >= a.start)) { result.end = a.end; }
    if ((a.end <= b.end) && (a.end >= b.start)) { result.end = b.end; }
    return result;
}

int valid_range(struct range a) {
    if (a.end < a.start) { return 0;}
    if (a.end == 0) { return 0;}
    return 1;
}

void main() {
    char buffer[200];
    struct range ranges[500];
    long unsigned int total = 0;
    for (int i=0; fgets(buffer,200,stdin); i++){
        ranges[i].start = 0;
        ranges[i].end = 0;
        if (buffer[0] == '\n') { break; }
        ranges[i] = get_range(buffer);
    }
    for (int i=0; ranges[i].end != 0; i++) {
        if (! valid_range(ranges[i])) { continue; }
        for (int j=0; ranges[j].end != 0; j++) {
            if (i ==j) { continue; }
            if (! valid_range(ranges[j])) { continue; }
            if (intersect(ranges[i],ranges[j])) {
                ranges[i] = get_result_range(ranges[i],ranges[j]);
                ranges[j].start = 2;
                ranges[j].end = 1;
            }
        }
    }
    for (int i=0; ranges[i].end != 0; i++) {
        if (! valid_range(ranges[i])) { continue; }
        total += (ranges[i].end - ranges[i].start + 1);
    }
    printf("%lu\n",total);
}