#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;

bool prime[N];

int main(){
    int n, m;
    int first;
    cin >> n >> m;
    for(int i = 2; i*i < N; i++) if(!prime[i])
        for(int j = 2*i; j < N; j += i)
            prime[j] = true;

    for(int i = n; i < N; i++)
        if(!prime[i]){
            first = i - n + 2;
            break;
        }

    cout << first + n - 2 << ' ' << first + n - 2 << endl;
    
    for(int i = 1; i < n - 1; i++)
        cout << i << ' ' << i + 1 << ' ' << 1 << '\n';

    cout << n - 1 << ' ' << n << ' ' <<  first << '\n';

    m -= n - 1;
    for(int i = 1; m; i++)
        for(int j = i + 2; m and j <= n; j++)
            cout << i << ' ' << j << ' ' << N << '\n', m--;
}
