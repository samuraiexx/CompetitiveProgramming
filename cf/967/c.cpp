#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
const ll INF = 0x3f3f3f3f;
ll st[N], el[N];

ll find_best(ll x1, ll x2, ll v[], ll n){
    if(x1 > x2) swap(x1, x2);
    ll bst = INF;

    auto it = lower_bound(v, v + n, x1);
    if(it < v + n and *it <= x2) return 0;

    if(--it >= v) bst = x1 - *it;

    it = lower_bound(v, v + n, x2);
    if(it < v + n) bst = min(bst, *it - x2);

    return 2*bst;
}

int main(){
  ll n, m, stn, eln, v;
  cin >> n >> m >> stn >> eln >> v;

  for(ll i = 0; i < stn; i++)
    cin >> st[i];
  for(ll i = 0; i < eln; i++)
    cin >> el[i];
  sort(st, st + stn);
  sort(el, el + eln);

  ll q;
  cin >> q;
  while(q--){
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll dy = abs(y1 - y2);
    ll dx = abs(x1 - x2);

    ll bel = find_best(y1, y2, el, eln);
    ll bst = find_best(y1, y2, st, stn);
    ll ans = min(bst + dx + dy, bel + dy + (dx + v - 1)/v);
    if(dx == 0) cout << dx + dy << endl;
    else cout << ans << endl;
 }
}
