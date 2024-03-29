#include<stdio.h>
#include<string.h>
#define N strlen(g)

char t[50], cs[50], g[50];
int a, e, c;

void xor() {
    for (c = 1; c < N; c++)
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');
}

void crc() {
    for (e = 0; e < N; e++)
        cs[e] = t[e];

    do {
        if (cs[0] == '1')
            xor();

        for (c = 0; c < N - 1; c++)
            cs[c] = cs[c + 1];

        cs[c] = t[e++];
    } while (e <= a + N - 1);
}

int main() {
    printf("\n Enter the data: ");
    scanf("%s", t);
    printf("\n Enter the generator polynomial: ");
    scanf("%s", g);
    a = strlen(t);

    for (e = a; e < a + N - 1; e++)
        t[e] = '0';

    printf("\n Modified data is: %s", t);
    crc();
    printf("\n Checksum is: %s", cs);

    for (e = a; e < a + N - 1; e++)
        t[e] = cs[e - a];

    printf("\n The final codeword is: %s", t);
    
    printf("\n Test error detection: 0 for YES and 1 for NO: ");
    scanf("%d", &e);

    if (e == 0) {
        do {
            printf("\n Enter the position where error is to be inserted: ");
            scanf("%d", &e);
        } while (e == 0 || e > a + N - 1);

        t[e - 1] = (t[e - 1] == '0') ? '1' : '0';
        printf("\n Erroneous data: %s\n", t);
    }

    crc();

    for (e = 0; (e < N - 1) && (cs[e] != '1'); e++);

    if (e < N - 1)
        printf("\n Error detected \n \n");
    else
        printf("\n No error detected \n \n");

    return 0;
}
