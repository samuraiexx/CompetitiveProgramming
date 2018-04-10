#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 1e5 + 5;
ll n, w;

struct Ap{
  ll x, v;
  const bool operator<(const Ap b)const{
    return x == b.x ? v < b.v : x < b.x;
  }
  const bool operator==(const Ap b)const{
    return x*(b.v + w) == b.x*(v + w);
  }
  const bool operator!=(const Ap b)const{
    return !(*this == b);
  }
}ap[N];

ll v[N], tmp[N];

ll cnt_rep(){
  ll cnt = 0;
  for(ll i = 0; i < n;){
    ll j;
    for(j = i + 1; j < n; j++)
      if(ap[i] != ap[j]) break;
    cnt += (j - i)*(j - i - 1)/2;
    i = j;
  }
  return cnt;
}

ll ms(ll l, ll r){
  if(l == r) return 0;
  ll cnt;
  ll mid = (l + r)/2;
  cnt = ms(l, mid) + ms(mid + 1, r);

  ll i = l, j = mid + 1;
  ll k = l;
  while(k <= r){
    if(j > r) tmp[k++] = v[i++];
    else if(i > mid) tmp[k++] = v[j++];
    else if(v[i] < v[j]) tmp[k++] = v[i++];
    else tmp[k++] = v[j++], cnt += (mid - i + 1);
  }

  for(ll i = l; i < k; i++)
    v[i] = tmp[i];

  return cnt;
}

int main(){
  map<Ap, ll> id;
  ll ans = 0;
  cin >> n >> w;

  for(ll i = 0; i < n; i++)
    cin >> ap[i].x >> ap[i].v;

  w = -w;
  stable_sort(ap, ap + n, [](Ap a, Ap b){
      return abs((a.v + w)*b.x) < abs((b.v + w)*a.x);});
  w = -w;
  stable_sort(ap, ap + n, [](Ap a, Ap b){
      return abs((a.v + w)*b.x) < abs((b.v + w)*a.x);});
  for(ll i = 0; i < n; i++) id[ap[i]] = i;

  if(w == 0) return cout << cnt_rep() << endl, 0;

  //for(int i = 0; i < n; i++) db(ap[i].x _ ap[i].v _ ap[i].x/(double)(ap[i].v + w)); cout << endl;

  ans += cnt_rep();

  w = -w;
  stable_sort(ap, ap + n, [](Ap a, Ap b){
      return abs((a.v + w)*b.x) < abs((b.v + w)*a.x);});
  for(ll i = 0; i < n; i++) v[i] = id[ap[i]];

  //for(int i = 0; i < n; i++) db(ap[i].x _ ap[i].v _ ap[i].x/(double)(ap[i].v + w)); cout << endl;

  ans += cnt_rep();
  ans += ms(0, n - 1);

  cout << ans << endl;
}
