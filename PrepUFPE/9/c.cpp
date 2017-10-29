#include <bits/stdc++.h>
using namespace std;

const int N = 1e2+5;
const int A = 2e6+5;

int n, v[N], coin[A], ok = 1;

int main () {
    memset(coin, 63, sizeof(coin));
    coin[0] = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    for (int i = 0; i < n; i++)
        for (int j = v[i]; j < A; j++)
            coin[j] = min(coin[j], 1+coin[j-v[i]]);
    for (int i = 1; i < A; i++) {
        int am = i;
        int ans = 0;
        int ind = n-1;
        while (am > 0 and ind >= 0) {
            ans += am/v[ind];
            am %= v[ind];
            ind--;
        }
        if (ans != coin[i]) ok = 0;
    }
    printf("%scanonical\n", ok ? "" : "non-");
    return 0;
}

