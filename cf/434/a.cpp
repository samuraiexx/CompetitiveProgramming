#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    map<ll, ll> div;
    ll n, k, ans = 1;
    cin >> n >> k;
    for(ll i = 2, x = n; i < 6; i++)
        while(x%i == 0) x/=i, div[i]++;
    while(max(div[2], div[5]) < k) ans *= 10, k--;
    while(k > 0 && min(div[2], div[5])) div[2]--, div[5]--, k--;
    while(k > 0)
    {
        if(div[2] > div[5])
            div[2]--, ans *= 5, k--;
        else
            div[5]--, ans *= 2, k--;
    }
    cout << ans*n << endl;
    return 0;
}
