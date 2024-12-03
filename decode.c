#include <stdio.h>
#include <stdlib.h>
void decode(FILE *fp);
int main(void) {
    FILE *fp = fopen("output.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        return 0;
    }
    decode(fp);
    fclose(fp);
    return 0;
}
void decode(FILE *fp) {
    int run, code;
    while (!feof(fp)) {
        run = fgetc(fp) - '0';
        code = fgetc(fp);
        for (int i = 0; i < run; i++) printf("%c", code);
    }
}
