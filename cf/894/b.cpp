#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

// Fast exponential
ll fexp(ll a, ll b, ll m = mod) {
    ll r=1;
    for (a %= m; b; b>>=1, a=(a*a)%m) if (b&1) r=(r*a)%m;
    return r;
}

int main(){
    ll m, n, k;
    cin >> m >> n >> k;
    if(m == 1 or n == 1){
        if((m%2 == 0 or n%2 == 0) and k == -1) return cout << 0 << endl, 0;
        else return cout << 1 << endl, 0;
    }
    ll pot = (((m - 1)%mod)*((n - 1)%mod))%mod;
    cout << fexp(2, pot) << endl;
    return 0;
}
