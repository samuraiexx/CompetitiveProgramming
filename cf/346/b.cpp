#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 

using namespace std;
const int N = 105;
int kmp[N];
int lcs[N][N][N];
bool vis[N][N][N];
tuple<int, int, int> from[N][N][N];

string s1, s2, v;

void kmpPre(){
  kmp[0] = -1;
  for(int j = -1, i = 0; i < v.size(); kmp[++i] = ++j){ 
    while(j >= 0 and v[i] != v[j]) j = kmp[j];
  }
}

int lcsf(int i, int j, int k){
  if(i < 0 or j < 0) return 0;
  if(vis[i][j][k]) return lcs[i][j][k];
  vis[i][j][k] = true;

  int nxt;
  lcs[i][j][k] = lcsf(i - 1, j, k), from[i][j][k] = {i - 1, j , k};

  nxt = lcsf(i, j - 1, k);
  if(lcs[i][j][k] < nxt)
    lcs[i][j][k] = nxt, from[i][j][k] = {i, j - 1, k};

  if(s1[i] == s2[j]){
    int k2 = k;
    while(k2 >= 0 and v[k2] != s1[i])
      k2 = kmp[k2];
    k2++;
    if(k2 != v.size()){
      nxt = 1 + lcsf(i - 1, j - 1, k2);
      if(lcs[i][j][k] < nxt)
        lcs[i][j][k] = nxt, from[i][j][k] = {i - 1, j - 1, k2};
    }
  }
  return lcs[i][j][k];
}

void recover(int i, int j, int k){
  if(i < 0 or j < 0) return;
  int i2, j2, k2;
  tie(i2, j2, k2) = from[i][j][k];
  recover(i2, j2, k2);

  if(i2 == i - 1 and j2 == j - 1)
    cout << s1[i];
}

int main(){
  cin >> s1 >> s2 >> v;
  reverse(v.begin(), v.end());

  kmpPre();
  int ans = 0;
  int k;
  for(int i = 0; i < v.size(); i++){
    int val = lcsf(s1.size() - 1, s2.size() - 1, i);
    if(ans < val)
      ans = val, k = i;
  }

  if(ans == 0) cout << 0 << endl;
  else{
    recover(s1.size() - 1, s2.size() - 1, k);
    cout << endl;
  }
}
