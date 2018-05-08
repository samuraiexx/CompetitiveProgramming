#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
set<string> used;
vector<set<char>> ci;
vector<vector<char>> li;
string ans;

void backtracking(string s, int w){
  if(w == li.size())
    if(used.count(s)) return;
    else { ans = s; return; }
  for(int i = 0; i < li[w].size() and ans.empty(); i++){
    s.push_back(li[w][i]);
    backtracking(s, w + 1);
    s.pop_back();
  }
}

int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    int n, l;
    cin >> n >> l;

    li.clear(); li.resize(l);
    ci.clear(); ci.resize(l);
    used.clear(); ans.clear();

    for(int i = 0; i < n; i++){
      //db(i);
      string s;
      cin >> s;
      //db(s);
      for(int j = 0; j < s.size(); j++)
        if(!ci[j].count(s[j])) 
          li[j].push_back(s[j]), ci[j].insert(s[j]);

      used.insert(s);
    }

    backtracking("", 0);
    cout << "Case #" << t << ": ";
    if(ans.size()) cout << ans << endl;
    else cout << "-" << endl;
  }
}
