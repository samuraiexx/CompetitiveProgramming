#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<
typedef long long ll;
const ll N = 1e5 + 5;
ll a[N], b[N];

int main(){
  ll n;
  ll lmn = -1e9, lmx = 1e9, rmn = -1e9, rmx = 1e9;
  cin >> n;
  for(ll i = 0; i < n; i++) cin >> a[i];
  for(ll i = 0; i < n; i++){
    char c;
    cin >> c;
    b[i] = c - '0';
  }

  for(ll i = 4; i < n; i++){
    ll mn = 1e9, mx = -1e9;
    ll bmn = 1, bmx = 0;
    for(ll j = i - 4; j <= i; j++)
      mx = max(a[j], mx), mn = min(mn, a[j]);
    for(int j = i - 4; j < i; j++)
      bmn = min(bmn, b[j]), bmx = max(bmx, b[j]);

    if(b[i] == 0 and bmn != 1) continue;
    if(b[i] == 1 and bmx != 0) continue;

    //db(i _ b[i]);
    if(b[i] == 0){
      if(b[i - 1] == 0) lmn = max(lmn, mn);
      else rmx = min(rmx, mn - 1);
    }else{
      if(b[i - 1] == 1) rmn = max(rmn, mx);
      else lmn = max(lmn, mx + 1);
      //db(b[i] _ b[i - 1] _  lmn _ mx + 1);
    }
  }

  cout << lmn << ' ' << rmx << endl;
}
