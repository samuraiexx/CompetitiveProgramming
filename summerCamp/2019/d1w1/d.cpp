#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int INF = 0x3f3f3f3f;
string s;
int p;
vector<vector<pair<int, char>>> dp;
vector<vector<bool>> vis;

pair<int, char> dpf(int i, int k){
  if(i == s.size()) return dp[i][k] = (k == 0 ? make_pair(0, 0) : make_pair(-INF, 0));

  if(vis[i][k]) return dp[i][k];
  vis[i][k] = true;

  auto p1 = dpf(i + 1, k);
  pair<int, char> p2 = {dpf(i + 1, (10*k + s[i] - '0')%p).st + 1, s[i]};

  dp[i][k] = max(p1, p2);

  return dp[i][k];
}

int main(){
  cin >> s >> p;
  dp = vector<vector<pair<int, char>>>(s.size() + 5, vector<pair<int, char>>(p + 5));
  vis = vector<vector<bool>>(s.size() + 5, vector<bool>(p));

  pair<int, char> mx = {-1, -1};
  int bg;

  for(int i = 0; i < s.size(); i++){
    pair<int, char> v = {dpf(i + 1, (s[i] - '0')%p).st + 1, s[i]};

    if(s[i] != '0' and v > mx)
      mx = v, bg = i;
  }

  bool ok = false;
  for(auto c : s) if(c == '0') ok = true;
  if(mx.st <= 0) return cout << (ok ? 0 : -1) << endl, 0;

  cout << s[bg];
  int k = (s[bg] - '0')%p;
  for(int i = bg + 1; i < s.size(); i++){
    auto pa = dpf(i, k);
    if(pa.st == 0) break;

    if(s[i] == pa.nd){
      cout << pa.nd;
      k = (k*10 + s[i] - '0')%p;
    }
  }

  cout << endl;
}
