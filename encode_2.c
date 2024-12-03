#include <stdio.h>
#define BUF_SIZE 102400
char buffer[BUF_SIZE];
void encode(FILE *fp, char *txt, int max);
int main(void) {
    FILE *fp_i = fopen("input.txt", "r");
    if (fp_i == NULL) {
        fclose(fp_i);
        return 0;
    }
    int i = 0;
    char c;
    while (i < BUF_SIZE && (c = fgetc(fp_i)) != EOF) {
        buffer[i] = c;
        i++;
    }
    fclose(fp_i);
    FILE *fp_o = fopen("output.txt", "w");
    encode(fp_o, buffer, i);
    fclose(fp_o);
    return 0;
}
void encode(FILE *fp, char *txt, int max) {
    int cnt = 1;
    for (int i = 0; i < max; i++) {
        if (txt[i] == txt[i + 1])
            cnt++;
        else {
            if (cnt >= 3)
                fprintf(fp, "@%d%c", cnt, txt[i]);
            else if (cnt == 2)
                fprintf(fp, "%c%c", txt[i], txt[i]);
            else
                fprintf(fp, "%c", txt[i]);
            cnt = 1;
        }
    }
}
