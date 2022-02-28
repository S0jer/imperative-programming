#include <stdio.h>
#include <math.h>

int check(a){
    int result = 0;
    while (a > 0){
        result += pow(a%10, 2);
        a = a/10;
    }
    if (result == 1){return 1;}
    else if (result == 4){return 0;}
    else{return check(result);}
}

int primes(a){
    int num = 5;
    if (a == 2 || a == 3) { return 1; }
    else if (a < 2 || a % 2 == 0 || a % 3 == 0) { return 0; }
    while ( num < powf(a, 0.5)) {
        if (a % num == 0) { return 0;}
        num += 2;
        if (a % num == 0) { return 0;}
        num += 4;
    }
    return 1;
}


void one_square(int l , int u, int k){
    int k_0 = 1, first = 0, x, y;
    for (int i = l; i <= u; ++i) {
        x = check(i); y = primes(i);
        if (x == 1 && y == 1 && k == k_0){ first = i; k_0 += 1; }
        else if (x == 1 && y == 1) { k_0 += 1; }
    }
    if (k_0 > k){ printf("%d", first); }
    else{ printf("%d", -1); }
}


int main() {
    int l, u, k;
    scanf("%d %d %d", &l, &u, &k);
    one_square(l, u, k);
}

