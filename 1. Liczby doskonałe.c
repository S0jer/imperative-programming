#include <stdio.h>
#include <stdbool.h>


bool perf(int m, int n){
    int ii, l = 0, z = 0, jj = 0, tab[10]={0,0,0,0,0,0,0,0,0,0}, check, x;
    if ( m < 1){ m = 1;}
    for ( ii = 1; jj*ii <= n; ii *= 2 ){
        jj += ii;
        check = 0;
        if (jj % 2 != 0) { for (x = 5; x < jj; x += 2) { if (jj % x == 0) {check = 1; break;}}
        if (check == 0 && jj*ii > m ){l += 1, tab[z] = jj*ii, z += 1;}}}
    printf("%d\n", l);
    for (z = 0; z < 10; z += 1){ if (tab[z] != 0){ printf("%d ", tab[z]); }}}



int main(){
    int m = 0, n = 0;
    scanf("%d%d", &m, &n);
    perf(m, n);
}







/*int RToA(char *x) {
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
 *
 *
 */