#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
map<char, int> cnt;
vector<int> amt;

int main(){
  string s;
  cin >> s;
  for(char c : s) cnt[c]++;

  if(cnt.size() > 4 or cnt.size() == 1) return cout << "No" << endl, 0;

  for(auto p : cnt) amt.pb(p.nd);
  sort(amt.begin(), amt.end());


  if(amt.size() == 2 and amt[0] == 1) return cout << "No" << endl, 0;
  if(amt.size() == 3 and amt[2] == 1) return cout << "No" << endl, 0;

  cout << "Yes" << endl;
}
