#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5 + 5;
ll nodes[N];

int main(){
    ll h;
    ll wh = -1;
    cin >> h;
    for(ll i = 0; i <= h; i++){
        cin >> nodes[i];
        if(nodes[i] > 1 and nodes[i - 1] > 1) wh = i;
    }
    if(wh == -1) return cout << "perfect" << endl, 0;
    cout << "ambiguous" << endl;
    
    cout << 0;
    ll sum = 1;
    for(ll i = 1; i <= h; i++){
        for(ll j = 0; j < nodes[i]; j++)
            cout << ' ' << sum;
        sum += nodes[i];
    }

    cout << endl <<  0;
    sum = 1;
    for(ll i = 1; i <= h; i++){
        for(ll j = 1; j < nodes[i]; j++)
            cout << ' ' << sum;

        if(i != wh) cout << ' ' << sum;
        else cout << ' ' << sum - 1;

        sum += nodes[i];
    }
    cout << endl;
    return 0;
}
