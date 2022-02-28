#include <stdio.h>

void fibo(int n){
    int a = 0, b = 1, c, check = 0;
    while ( a*b <= n ) {
        if (a * b == n) { check = 1; break;}
        c = b; b = a + b; a = c;}
    if ( check == 1) { printf("YES"); }
    else { printf("NO"); }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    fibo( n );
}
