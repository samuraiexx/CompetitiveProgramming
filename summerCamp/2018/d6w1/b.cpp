#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 8e3 + 5;
ll p = 1e9 + 7;
ll q = 7;
ll q2 = 31;

ll fexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b%2) ans = (ans*a)%p;
        a = (a*a)%p;
        b /= 2;
    }
    return ans;
}

ll hs[N];
ll hs2[N];
ll pot[N];
ll ipot[N];
ll pot2[N];
ll ipot2[N];

int main(){
    cin.tie(0), ios_base::sync_with_stdio(false);
    ll ans = 0;
    map<pair<ll, ll>, ll> st;
    string s;
    cin >> s;
    pot[0] = 1, pot2[0] = 1;
    ipot[0] = 1, ipot2[0] = 1;
    ipot[1] = fexp(q, p - 2), ipot2[1] = fexp(q2, p - 2);

    for(ll i = 1; i < N; i++) pot[i] = (pot[i - 1]*q)%p, pot2[i] = (pot2[i - 1]*q2)%p;
    for(ll i = 1; i < N; i++) ipot[i] = (ipot[i - 1]*ipot[1])%p, ipot2[i] = (ipot2[i - 1]*ipot2[1])%p;

    hs[0] = hs2[0] = s[0]%p;
    for(ll i = 1; i < s.size(); i++)
        hs[i] = (hs[i - 1] + (s[i]*pot[i])%p)%p,
        hs2[i] = (hs2[i - 1] + (s[i]*pot2[i])%p)%p;

    ll n = s.size();
    for(ll i = 0; i < n; i++)
        for(ll j = i; j < n; j++)
            if(i > 0)
                st[make_pair(((((hs[j] - hs[i - 1]) + p)%p)*ipot[i])%p, ((((hs2[j] - hs2[i - 1]) + p)%p)*ipot2[i])%p)] = j - i + 1;
            else 
                st[make_pair(hs[j], hs2[j])] = j - i + 1;

    for(auto p : st) ans += p.second;

    cout << ans << endl;
}
