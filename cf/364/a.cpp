#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 4e5;
int ps[N];
ll cnt[N];

int main(){
  int a;
  string s;
  cin >> a >> s;

  s = '0' + s;
  for(int i = 1; i < s.size(); i++)
    ps[i] = ps[i - 1] + s[i] - '0';

  ll sum = 0;
  for(int i = 1; i < s.size(); i++)
    for(int j = 0; j < i; j++)
      cnt[ps[i] - ps[j]]++, sum++;

  if(a == 0)
    return cout << 2*cnt[0]*sum - cnt[0]*cnt[0] << endl, 0;

  ll ans = 0;
  for(int i = 1; i < s.size(); i++)
    for(int j = 0; j < i; j++){
      int x = ps[i] - ps[j];
      if(x > 0 and a%x == 0 and a/x < N)
        ans += cnt[a/x];
    }

  cout << ans << endl;

}
