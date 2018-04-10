#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e2 + 5;
const int INF = 0x3f3f3f3f;
string s1, s2;
int dp[N][N];
pair<int, int> to[N][N];
char c[N][N];

int dpf(int i, int j){
  if(dp[i][j]) return dp[i][j];
  if(i == s1.size() and j == s2.size()) return to[i][j] = {INF, INF}, 0;
  if(i > s1.size() or j > s2.size()) return INF;

  if(s1[i] == s2[j])
    return to[i][j] = {i + 1, j + 1}, c[i][j] = s1[i], dp[i][j] = 1 + dpf(i + 1, j + 1);
  
  int ipp = dpf(i + 1, j), jpp = dpf(i, j + 1);
  if(ipp < jpp)
    return to[i][j] = {i + 1, j}, c[i][j] = s1[i], dp[i][j] = 1 + ipp;
  else
    return to[i][j] = {i, j + 1}, c[i][j] = s2[j], dp[i][j] = 1 + jpp;
}

int main(){
  int cnt = 0;
  while(cin >> s1 >> s2){
    cnt++;
    memset(dp, 0, sizeof dp);

    dpf(0, 0);

    pair<int, int> x = {0, 0};
    cout << "Teste " << cnt << endl;
    while(x != make_pair(INF, INF))
      cout << c[x.st][x.nd], x = to[x.st][x.nd];

    cout << endl << endl;
  }
}
