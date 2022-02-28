#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Program który dostaje 2 liczby całkowite a,b ; które wyznaczają zakres od (a , b)
// i należy sprawdzić czy w danym zakresie wszystkie liczby spełniają hipotezę Goldbacha
// czyli: "każda liczba naturalna parzysta większa od 2 jest sumą dwóch liczb pierwszych."

bool is_prime(int num) {
    int ii;
    if (num < 2) {return false;}
    if (num == 2) {return true;}
    if (num == 3) {return true;}
    if (num % 2 == 0) {return false;}
    if (num % 3 == 0) {return false;}
    for (ii = 5; ii * ii <= num; ii += 2) {
        if (num % ii == 0) {return false;}}return true;}

bool goldbach(int a, int b) {
    int ii;
    if (a % 2 == 1) { a += 1; }
    for (ii = a; ii <= b; ii += 2) {
        int ii_c = ii; int check = 0; int x = 0;
        while (ii_c > 0) {
            ii_c -= 1; x += 1;
            if (is_prime(ii_c) && is_prime(x)) {check = 1; break;}}
        if (check != 1){return false;}}return true;}

int main() {
    int a = 0; int b = 0;
    printf("Podaj liczbe a, większą od 4: "); scanf("%d", &a);
    printf("Podaj liczbę b, większą od %d: ", a); scanf("%d", &b);
    bool T = goldbach(a, b);
    if (T==true) {printf("Liczby z zakresu od %d do %d spełniają hipotezę Goldbacha", a, b);}
    else {printf("Liczby z zakresu od %d do %d nie spełniają hipotezy Goldbacha", a, b);}}
