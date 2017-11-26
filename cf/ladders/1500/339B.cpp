#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;

    ll lh = 1;
    ll dist = 0;
    for(ll i = 0; i < m; i++){
        ll nh;
        cin >> nh;
        if(nh >= lh) dist += nh - lh;
        else dist += n + nh - lh;
        lh = nh;
    }

    cout << dist << endl;
    return 0;
}
