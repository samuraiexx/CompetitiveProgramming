#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 305;
map<string, int> m;
map<vector<int>, int> ids;
int szs[N*N];
int szw[N*N];
int eco[N*N];

set<int> st[N];

int sz[N];

vector<int> w;
int cnt;
int cnts;

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    if(!m.count(s)) sz[cnt] = s.size(), m[s] = cnt++;
    w.push_back(m[s]);
  }

  for(int i = 0; i < n; i++){
    vector<int> v;
    int sum = 0;
    for(int j = i; j < n; j++){
      sum += sz[w[j]];
      v.push_back(w[j]);

      if(!ids.count(v)){
        int id = cnts;
        ids[v] = cnts++;

        szs[id] = sum + v.size() - 1;
        eco[id] = szs[id] - v.size();
        szw[id] = v.size();
      }
      st[i].insert(ids[v]);
    }
  }

  int ans = 0;

  for(int i = 0; i < n; i++){
    for(auto s : st[i]){
      int cnt = 1;
      for(int j = i + szw[s]; j < n; j++){
        if(st[j].count(s)) cnt++, j += szw[s] - 1;
      }
      if(eco[s]*cnt > ans and cnt > 1)
        ans = eco[s]*cnt; 
    }
  }


  int total = w.size() - 1;
  for(int i = 0; i < n; i++)
    total += sz[w[i]];

  cout << total - ans << endl;
}
