#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  string s, t;
  map<char, set<int>> m;
  cin >> s;
  t = s;
  sort(t.begin(), t.end());

  for(int i = s.size() - 1; i >= 0; i--)
    m[t[i]].insert(i);

  for(int i = 0; i < s.size(); i++){
    if(s[i] == t[i]) continue;
    int x = *(m[s[i]].lower_bound(i));
    m[t[i]].insert(x);
    m[s[i]].erase(x);
    t[x] = t[i];


    if(t[i] > s[i]) cout << i + 1 << ' ' << x + 1 << endl;
    else cout << x + 1 << ' ' << i + 1 << endl;
  }
}
