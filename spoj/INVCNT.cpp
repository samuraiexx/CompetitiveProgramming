#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<
typedef long long ll;

const ll N = 2e5 + 5;
ll v[N], tmp[N];

ll merge_sort(ll l, ll r){
  if(l == r) return 0;
  ll mid = (l + r)/2;
  
  ll inv = merge_sort(l, mid) + merge_sort(mid + 1, r);

  ll k = 0;
  ll i = l, j = mid + 1;
  while(i <= mid or j <= r){
    if(i > mid) tmp[k++] = v[j++];
    else if(j > r or v[i] <= v[j]) tmp[k++] = v[i++];
    else tmp[k++] = v[j++], inv += mid - i + 1;
  }

  for(ll i = 0; i < k; i++)
    v[l + i] = tmp[i];

  return inv;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(0);
  ll t;
  cin >> t;
  for(ll i = 0; i < t; i++){
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++)
      cin >> v[i];
    
    cout << merge_sort(0, n-1) << '\n';
  }
}
