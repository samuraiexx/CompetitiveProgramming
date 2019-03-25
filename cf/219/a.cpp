#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
int cnt[26];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int k;
  string s;
  cin >> k >> s;

  for(auto c : s)
    cnt[c - 'a']++;

  string ans;
  for(int i = 0; i < 26; i++){
    if(cnt[i]%k) return cout << -1 << endl, 0;
    for(int j = 0; j < cnt[i]/k; j++)
      ans.pb('a' + i);
  }

  for(int i = 0; i < k; i++)
    cout << ans;
  cout << endl;
}
