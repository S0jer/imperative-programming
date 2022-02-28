#include <stdio.h>


void primes(int n) {
    int ii, num, check_1, check_2, x, num_c;
    if (2 < n) { printf("%d\n", 2); }
    if (3 < n) { printf("%d\n", 3); }
    for (num = 5; num < n; num += 2) {
        check_1 = 0;
        if (num % 2 != 0 && num % 3 != 0)
        { for (ii = 5; ii * ii <= num; ii += 2) { if (num % ii == 0) { check_1 = 1; break; }}
            if (check_1 == 0 ) {
                x = num % 10; check_2 = 0;
                for (num_c = num/10 ; num_c != 0; num_c /= 10){
                    if ( x < num_c%10 ) { check_2 = 1; }
                    x = num_c%10; }
                if (check_2 == 0 ) { printf("%d\n", num); }}}}}

int main() {
    int n = 0;
    scanf("%d", &n);
    primes(n);
}






