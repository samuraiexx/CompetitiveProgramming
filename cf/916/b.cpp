#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    map<ll, ll, greater<ll>> ones;
    ll n, k;
    cin >> n >> k;
    for(ll i = 0; n; i++, n /= 2)
        if(n%2) ones[i]++;

    if(ones.size() > k) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    
    k -= ones.size();

    for(auto &a : ones){
        while(a.second and k)
            a.second--, k--, ones[a.first-1]+=2;
        if(!k) break;
    }

    for(auto a : ones)
        for(ll i = 0; i < a.second; i++)
            cout << a.first << ' ';

    cout << endl;
}
