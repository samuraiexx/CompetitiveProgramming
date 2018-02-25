#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;

    bool f = 0;
    if(k > 1)
        for(ll i = 62; i >= 0; i--)
            if(!f and (1ll << i)&n) f = true;
            else if(f) n = n|(1ll << i);

    cout << n << endl;
}
