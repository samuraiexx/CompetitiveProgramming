#include<bits/stdc++.h>
using namespace std;

int v[1005], n, x;

int main(){
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        for (int i = 1; i <= x; i++) scanf("%d", &v[i]);
        for (int i = 2; i <= x-1; i++) {
            if (v[i-1] + 1 == v[i+1]) {
                printf("%d\n", i);
                break;
            }
        }
    }
}
