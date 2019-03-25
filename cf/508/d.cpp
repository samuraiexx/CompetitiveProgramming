#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
map<string, int> m;
string rm[N];
int cnt = 0;
vector<int> adj[N];
int in[N];
vector<int> ans;

int get_id(string &s){
  if(m.count(s)) return m[s];
  else return rm[cnt] = s, m[s] = cnt++;
}

void add(string &s, char c){
  string s2;
  s2.pb(s[0]), s.pb(s[1]), s.pb(c);

  if(m.count(s2)) adj[m[s]].pb(m[s2]), in[m[s2]]++;
}

void dfs(int v){
  while(adj[v].size()){
    int x = adj[v].back();
    adj[v].pop_back();
    dfs(x);
  }
  ans.pb(v);
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    string s1, s2;
    s1.pb(s[0]), s1.pb(s[1]);
    s2.pb(s[1]), s2.pb(s[2]);

    adj[get_id(s1)].pb(get_id(s2));
    in[get_id(s2)]++;
  }

  vector<int> v;
  for(int i = 0; i < cnt; i++) if(adj[i].size() != in[i]){
    if(abs((int)adj[i].size() - in[i]) != 1) return cout << "NO\n", 0; 
    v.pb(i);
  }

  if(v.size()){
    if(v.size() != 2) return cout << "NO\n", 0;
    if(in[v[0]] > adj[v[0]].size()) swap(v[0], v[1]);
    if(in[v[0]] > adj[v[0]].size()) return cout << "NO\n", 0;
    adj[v[1]].pb(v[0]);
  }

  dfs(0);
  for(int i = 0; i < cnt; i++)
    if(adj[i].size()) return cout << "NO\n", 0;
  ans.pop_back();

  reverse(ans.begin(), ans.end());
  int bg = 0;
  if(v.size()){
    for(int i = 0; i < ans.size(); i++)
      if(ans[i] == v[1] and ans[(i + 1)%ans.size()] == v[0]){
        bg = i + 1;
        break;
      }
  }
  
  cout << "YES\n" << rm[ans[bg]][0];
  for(int i = 0; i < ans.size() + (v.size() == 0); i++)
      cout << rm[ans[(bg + i)%ans.size()]][1];
  cout << endl;
}
