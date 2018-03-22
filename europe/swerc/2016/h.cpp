#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll psc[32][32];

set<ll> dp[32][32];

int main(){

    ll d, h;
    cin >> d >> h;
    for(ll i = 0; i < 32; i++)
        psc[0][i] = psc[i][0] = 1;
    for(ll i = 1; i < 32; i++)
        for(ll j = 1; j < 32 - i; j++)
            psc[i][j] = psc[i - 1][j] + psc[i][j - 1];


    for(ll i = 0; i < h; i++)
    {
        for(ll j = 0; j <= i; j++)
            dp[2][i].insert(psc[i - j][j]);// cout << psc[i - j][j] << endl;
    }

    for(ll i = 3; i <= d; i++)
        for(ll j = 0; j < h; j++)
            for(ll k = 0; k <= j; k++)
                for(auto a : dp[i - 1][k])
                    dp[i][j].insert(a*psc[k][j - k]);

    for(auto a : dp[d][h - 1])
        cout << a << '\n';

    return 0;
    
}
