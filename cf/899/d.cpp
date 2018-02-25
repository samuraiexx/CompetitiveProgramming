#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, ans = 0;
    vector<ll> mx;
    vector<ll> pd;

    for(ll i = 1; i < 3e9; i*=10) pd.push_back(i);
    cin >> n;
    if(n < 5){
        if(n == 1) cout << 0 << endl;
        if(n == 2) cout << 1 << endl;
        if(n == 3) cout << 3 << endl;
        if(n == 4) cout << 6 << endl;
        return 0;
    }

    ll x = 2*n, sz = 0, vx;
    while(x) vx = x, x /= 10, sz++;

    ll a = 0;
    for(ll i = 1, j = 1; i < sz; i++, j*=10)
        a += 9*j;
    for(ll i = vx - 1; i >= 0; i--)
        mx.push_back(a + pd[sz - 1]*i);

    for(auto x : mx)
        if(x > n) ans += (2*n - x + 1)/2;
        else ans += (x)/2;

    cout << ans << endl;
}
