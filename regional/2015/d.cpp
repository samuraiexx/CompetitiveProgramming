#include <bits/stdc++.h>
using namespace std;

#define px first
#define py second
typedef long long ll;
const ll N = 1e5 + 1;

ll n;
pair<ll, ll> pnts[N];
ll area[N];
ll total;

ll t_area(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3){
    return p1.px*p2.py + p2.px*p3.py + p3.px*p1.py
          - p1.py*p2.px - p2.py*p3.px - p3.py*p1.px;
}

ll p_area(ll i, ll j){
   if(i > j) swap(i, j);
   ll mx = area[j] - area[i] - t_area(pnts[0], pnts[i], pnts[j]);
   return max(mx, total - mx); 
}

int main(){
    cin >> n;
    for(ll i = 0; i < n; i++)
        cin >> pnts[i].px >> pnts[i].py;
    for(ll i = 1; i < n; i++)
        area[i] = area[i - 1] + t_area(pnts[0], pnts[i - 1], pnts[i]);
    total = area[n - 1];
    ll mx = 0;
    for(ll i = 0; i < n; i++){
        ll a = i + 2, b = n + i - 2;
        while(b - a > 3)
        {
            ll a1 = (a + b)/2;
            ll b1 = a1 + 1;
            if(p_area(i, a1%n) > p_area(i, b1%n)) 
                a = a1;
            else b = b1;
        }
        mx = max(mx, min(min(p_area(i, a%n), p_area(i, (a+1)%n)), p_area(i, (a+2)%n)));
    }
    cout << mx << ' ' << total - mx << endl;
    return 0;
}
