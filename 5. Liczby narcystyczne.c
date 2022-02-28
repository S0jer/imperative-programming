#include <stdio.h>
#include <math.h>


void dectoanother(int a, int b) {
    int number = a, result;
    if (number != 0) {
        dectoanother( a / b, b);
        result = number % b;
        if (result <= 9){printf("%d", result);}
        else if (result == 10){printf("A");}
        else if (result == 11){printf("B");}
        else if (result == 12){printf("C");}
        else if (result == 13){printf("D");}
        else if (result == 14){printf("E");}
        else if (result == 15){printf("F");}
        }}

int len(int start, int b){
    int length = 0;
    while (start != 0){ start = start / b; length += 1;}
    return length;}

int is_narc(int start, int b, int m){
    int result = 0;
    while ( start != 0 ){ result += pow( start%b , m); start = start / b; }
    return result;}


int narc(int m, int b){
    int  control = 0, start = 0, x = 0;
    while ( x <= m ){
        x = len(start, b);
        if (x == m){ if (start == is_narc(start, b, m)){dectoanother(start, b); printf(" "); control = 1;}}
        start += 1;
    }return control;}


int main() {
    int m, b, a;
    scanf("%d%d", &m, &b);
    a = narc(m ,b);
    if (a == 0){ printf("NO"); }
}
