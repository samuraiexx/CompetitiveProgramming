#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 3e5 + 5;
pair<ll, ll> s[N];

int main(){
  ll n, x1, x2, y1, y2;
  cin >> n >> x1 >> x2;
  y1 = x1, y2 = x2;

  for(ll i = 0; i < n; i++)
    cin >> s[i].st, s[i].nd = i + 1;
  sort(s, s + n);

  ll k = 2;
  while(k--){
    ll mn = n;
    ll x;
    for(ll i = 0; i < n; i++){
      ll amt = (y1 + s[i].st - 1)/s[i].st;
      if(i + amt < mn) mn = amt + i, x = i;
    }
    
    bool tryagain = true;
    int y;

    for(ll i = mn; i < n; i++)
      if(i + (y2 + s[i].st - 1)/s[i].st <= n) 
        tryagain = false, y = i;
      
    if(tryagain) { swap(y1, y2); continue; }
    cout << "Yes" << endl;

    vector<ll> s1, s2;
    for(ll i = x; i < mn; i++)
      s1.push_back(s[i].nd);
    for(ll i = y; i < n; i++)
      s2.push_back(s[i].nd);

    if(y1 != x1) swap(s1, s2);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    cout << s1.size() << ' ' << s2.size() << endl;
    for(auto x : s1) cout << x << ' ';
    cout << endl;
    for(auto x : s2) cout << x << ' ';
    cout << endl;
    return 0;
  }
  cout << "No" << endl;
}
