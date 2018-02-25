#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define st first
#define nd second
#define pb push_back
const ll N = 3e5 + 25;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll bit[N]; //query(i) retorna qnts meteoros cairam na orbinta i
ll ss[N]; // space station, para cada orbita diz qual o estado nela
ll ia[N]; // intended amount, diz para cada estado quantos meteoros quer coletar
ll fday[N]; //final day, o primeiro dia em q a quantidade de meteoros eh >= ao pretendido, ou 0
pair<ll, ll> ms[N]; // meteor_shower - diz o range l r da chuva i
ll ms_amt[N]; // meteor_shower amount - diz quantos meteoros cairam na chuva i
vector<ll> adj[N]; //para cada estado i, diz as orbitas q pertencem a ele
ll n, m, k;
ll pnt = 0;

void add(ll a, ll b, ll v){
  for(;a <= m; a+=a&-a) bit[a] += v;
  b++;
  for(;b <= m; b+=b&-b) bit[b] -= v;
}

ll query(ll x){
  ll ret = 0;
  for(ll p = x; p > 0; p -= p&-p) ret += bit[p];
  return ret;
}

void p_bsearch(vector<ll> &v, ll l, ll r){
  if(v.empty()) return;
  ll mid = (l+r)/2;

  while(pnt < mid){
    pnt++;
    auto p = ms[pnt];
    if(p.st <= p.nd) add(p.st, p.nd, ms_amt[pnt]);
    else add(p.st, m, ms_amt[pnt]), add(1, p.nd, ms_amt[pnt]);
  }

  while(pnt > mid){
    auto p = ms[pnt];
    if(p.st <= p.nd) add(p.st, p.nd, -ms_amt[pnt]);
    else add(p.st, m, -ms_amt[pnt]), add(1, p.nd, -ms_amt[pnt]);
    pnt--;
  }

  if(l == r){
    for(ll a : v){
      ll sum = 0;
      for(ll b : adj[a]) sum = min(sum + query(b), INF);
      if(ia[a] <= sum) fday[a] = l;
      else fday[a] = -1;
    }
    return;
  }

  vector<ll> lv, rv;
  for(ll a : v){
    ll sum = 0;
    for(ll b : adj[a]) sum = min(sum + query(b), INF);
    if(sum >= ia[a]) lv.pb(a);
    else rv.pb(a);
  }

  p_bsearch(lv, l, mid);
  p_bsearch(rv, mid + 1, r);
}

int main(){
  cin >> n >> m;
  for(ll i = 1; i <= m; i++) cin >> ss[i], adj[ss[i]].push_back(i);
  for(ll i = 1; i <= n; i++) cin >> ia[i];
  cin >> k;

  for(ll i = 1; i <= k; i++) cin >> ms[i].st >> ms[i].nd >> ms_amt[i];

  vector<ll> all;
  for(ll i = 1; i <= n; i++) all.pb(i);

  p_bsearch(all, 1, k);

  for(ll i = 1; i <= n; i++)
    if(fday[i] != -1) cout << fday[i] << endl;
    else cout << "NIE" << endl;
}
