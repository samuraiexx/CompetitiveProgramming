#include<bits/stdc++.h>
using namespace std;

int cnt[26];

int main(){
  string s;
  while(cin >> s){
    int ans = 0;
    memset(cnt, 0, sizeof cnt);
    for(auto c : s) cnt[c - 'a'] ^= 1;
    for(int i = 0; i < 26; i++) if(cnt[i] & 1) ans++;
    cout << max(ans - 1, 0) << endl;
  }
}
