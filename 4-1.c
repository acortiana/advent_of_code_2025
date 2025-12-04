#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int accessible_roll(char matrix[150][150], int y, int x, int len_y, int len_x) {
    if (matrix[y][x] != '@') { return 0; }
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
	    int new_x = dx + x;
	    int new_y = dy + y;
            if ((dy == 0) && (dx == 0)) { continue; }
            if ((new_y < 0) || (new_y >= len_y)) { continue; }
            if ((new_x < 0) || (new_x >= len_x)) { continue; }
	    if (matrix[new_y][new_x] == '@') { count++; }
	}
    }
    if (count < 4) { return 1;}
    return 0;
}

void zeroize_newline(char *string) {
    int len = strlen(string);
    for (int i=0; i < len; i++) {
        if (string[i] == '\n') { string[i] = 0; }
    }
}

void main() {
    char buffer[150];
    char matrix[150][150];
    int len_x = 0;
    int len_y = 0;
    int total = 0;
    for (int i=0; fgets(buffer,150,stdin); i++) {
        zeroize_newline(buffer);
	memcpy(matrix[i],buffer,150);
	matrix[i+1][0] = 0;
	len_y++;
    }
    for (int i=0; matrix[0][i] != 0; i++) { len_x++; }
    for (int y = 0; y < len_y; y++) {
        for (int x = 0; x < len_x; x++) {
	    int result = accessible_roll(matrix,y,x,len_y,len_x);
            total += result;
	}
    }
    printf("%d\n",total);
}

