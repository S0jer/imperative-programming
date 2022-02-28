#include <stdio.h>

int RToA(char *x) {
    int wynik = 0;
    for (int i = 0; i <= 24; i++) {
        if (x[i] == 'I' && x[i + 1] == 'V') {
            wynik += 4;
            i++;
        } else if (x[i] == 'I' && x[i + 1] == 'X') {
            wynik += 9;
            i++;
        } else if (x[i] == 'X' && x[i + 1] == 'L') {
            wynik += 40;
            i++;
        } else if (x[i] == 'X' && x[i + 1] == 'C') {
            wynik += 90;
            i++;
        } else if (x[i] == 'C' && x[i + 1] == 'D') {
            wynik += 400;
            i++;
        } else if (x[i] == 'C' && x[i + 1] == 'M') {
            wynik += 900;
            i++;
        } else if (x[i] == 'I') {
            wynik++;
        } else if (x[i] == 'V') {
            wynik += 5;
        } else if (x[i] == 'X') {
            wynik += 10;
        } else if (x[i] == 'L') {
            wynik += 50;
        } else if (x[i] == 'C') {
            wynik += 100;
        } else if (x[i] == 'D') {
            wynik += 500;
        } else if (x[i] == 'M') {
            wynik += 1000;
        } else if (!(x[i])) {
            break;
        }
    }
    return wynik;
}

void printR(int number) {
    int num[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    char *sym[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    while (number > 0) {
        int div = number / num[i];
        number = number % num[i];
        while (div--) {
            printf("%s", sym[i]);
        }
        i--;
    }
}


int main() {
    char rome_1[1000], rome_2[1000];
    scanf("%s %s", rome_1, rome_2);
    int r_r = 0;
    r_r += RToA(rome_1);
    r_r += RToA(rome_2);
    printR(r_r);
}

