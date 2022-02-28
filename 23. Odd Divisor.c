#include <stdio.h>


int main() {
    int n, cnt, i;
    scanf("%lld", &n);

    long long result = 0, x, q;
    for (i = 1; i <= (n / 2); i += 2) {
        cnt = 0;
        x = i * 2;
        while (x <= n) {
            cnt++;
            x *= 2;
        }
        result += cnt * i;
    }

    if (n % 2 == 0) {
        q = (n - 2) / 2 + 1;
        result += ((1 + n - 1) / 2) * q;
    } else {
        q = (n - 1) / 2 + 1;
        result += ((1 + n) / 2) * q;
    }
    printf("%lld", result);

}


