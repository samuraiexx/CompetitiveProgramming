#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 

string s, s2;

int cnt[26];

int first(){return 0;}

void invert(int amt){
  string rev;
  for(int i = s.size() - 1; i >= s.size() - amt; i--)
    rev.pb(s[i]);
  for(int i = 0; i < s.size() - amt; i++)
    rev.pb(s[i]);
  s = rev;
}

int main(){
  cin >> s >> s2;

  for(auto c : s) cnt[c - 'a']++;
  for(auto c : s2) cnt[c - 'a']--;
  for(int i = 0; i < 26; i++)
    if(cnt[i]) return cout << -1 << endl;

  while(s != s2){
    int x;
    for(x = 0; x < n; x++) if(
  }
}
