#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 1e2;
const int p = 1e9 + 7;
int Div[N];
ll inv[N];
ll fac[N];
ll ifac[N];
map<int, int> mdiv[N];

ll fexp(ll a, ll b, ll m = p){
    ll r=1;
    for(a %= m; b; b>>=1, a=(a*a)%m) if(b&1) r= (r*a)%m;
    return r;
}
int main(){
    fac[0] = ifac[0] = 1;
    Div[1] = inv[1] = fac[1] = ifac[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (p - (p/i)*inv[p%i]%p)%p;
    for(int i = 2; i < N; i++) fac[i] = (fac[i - 1]*i)%p;
    for(int i = 2; i < N; i++) ifac[i] = (ifac[i - 1]*inv[i])%p;

    for(int i = 2; i*i < N; i++)
        if(!Div[i]) for(int j = i; j <= N; j += i)
            Div[j] = i;

    for(int i = 2; i < N; i++){
        if(!Div[i]){ mdiv[i][i] = 1; continue; } //prime
        mdiv[i][Div[i]] = 1;
        for(auto a : mdiv[i/Div[i]]) mdiv[i][a.first] += a.second;
    }

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int x, y;
        ll ans = 1;
        cin >> x >> y;

        for(auto a : mdiv[x]){
            ll tmp = fac[y - 1 + a.second];
            tmp = (tmp*ifac[a.second])%p;
            tmp = (tmp*ifac[y - 1])%p;
            ans = (ans*tmp)%p;
        }

        ans = (ans*fexp(2, y - 1))%p;

        cout << ans << endl;
    }

    return 0;
}
