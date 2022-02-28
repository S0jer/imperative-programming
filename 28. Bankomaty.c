#include <stdio.h>
#include <malloc.h>
#include <string.h>


void divide(int t[], int i) {
    if (t[0] == 0) { t[0] = 1; }
    else { t[0] = 0; }
    for (int j = 1; j <= i; j++) {
        if (t[j] % 2 == 0) t[j] /= 2;
        else {
            t[j] /= 2;
            if (j + 1 <= i) t[j + 1] += 10;
        }
    }
}


int main() {
    char number[30];
    int n, *Num, result[100] = {0};
    scanf("%s", number);
    n = strlen(number);

    Num = malloc((n + 1) * sizeof(int *));
    Num[0] = 0;


    for (int i = 0; i < n; ++i) {
        if (number[i] == '0') { Num[i + 1] = 0; }
        else if (number[i] == '1') { Num[i + 1] = 1; }
        else if (number[i] == '2') { Num[i + 1] = 2; }
        else if (number[i] == '3') { Num[i + 1] = 3; }
        else if (number[i] == '4') { Num[i + 1] = 4; }
        else if (number[i] == '5') { Num[i + 1] = 5; }
        else if (number[i] == '6') { Num[i + 1] = 6; }
        else if (number[i] == '7') { Num[i + 1] = 7; }
        else if (number[i] == '8') { Num[i + 1] = 8; }
        else if (number[i] == '9') { Num[i + 1] = 9; }
    }

    for (int i = 0; i < 100; ++i) {
        result[i] = Num[n] % 2;
        if (Num[0] == 0) { Num[n] -= result[i]; }
        else { Num[n] += result[i]; }
        divide(Num, n);
    }

    if (Num[n] != 0) {
        printf("NO");
    } else {

        for (int i = 0; i < 100; ++i) {
            if (result[i] == 1) {
                printf("%d ", i);
            }

        }
    }
    printf("\n");


    Num[0] = -1;


    for (int i = 0; i < n; ++i) {
        if (number[i] == '0') { Num[i + 1] = 0; }
        else if (number[i] == '1') { Num[i + 1] = 1; }
        else if (number[i] == '2') { Num[i + 1] = 2; }
        else if (number[i] == '3') { Num[i + 1] = 3; }
        else if (number[i] == '4') { Num[i + 1] = 4; }
        else if (number[i] == '5') { Num[i + 1] = 5; }
        else if (number[i] == '6') { Num[i + 1] = 6; }
        else if (number[i] == '7') { Num[i + 1] = 7; }
        else if (number[i] == '8') { Num[i + 1] = 8; }
        else if (number[i] == '9') { Num[i + 1] = 9; }
    }

    for (int i = 0; i < 100; ++i) {
        result[i] = Num[n] % 2;
        if (Num[0] == 0) { Num[n] -= result[i]; }
        else { Num[n] += result[i]; }
        divide(Num, n);
    }

    if (Num[n] != 0) {
        printf("NO");
    } else {

        for (int i = 0; i < 100; ++i) {
            if (result[i] == 1) {
                printf("%d ", i);
            }

        }
    }

}
