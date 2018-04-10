#include<bits/stdc++.h>
using namespace std;

void mult(vector<vector<long long>> &m1, vector<vector<long long>> &m2, const long long mod){
  vector<vector<long long>> tmp(m1.size());
  for(int i = 0; i < m1.size(); i++) tmp[i].resize(m1.size());
  for(int i = 0; i < m1.size(); i++)
    for(int j = 0; j < m1.size(); j++)
      for(int k = 0; k < m1.size(); k++)
        tmp[i][j] = (tmp[i][j] + m1[i][k]*m2[k][j])%mod;

  for(int i = 0; i < m1.size(); i++)
    for(int j = 0; j < m1.size(); j++)
      m1[i][j] = tmp[i][j];
}

void fexp(vector<vector<long long>> &m1, int b, const long long mod){
  vector<vector<long long>> tmp(m1.size());
  for(int i = 0; i < m1.size(); i++) tmp[i].resize(m1.size()), tmp[i][i] = 1;

  while(b){
    if(b&1) mult(tmp, m1, mod), b--;
    else mult(m1, m1, mod), b /= 2;
  }

  for(int i = 0; i < m1.size(); i++)
    for(int j = 0; j < m1.size(); j++)
      m1[i][j] = tmp[i][j];
}

int automata(vector<int> &A, vector<int> &B, vector<int> &C, int D, int E) {
  const int mod = 1e9 + 7;
  vector<vector<long long>> m(A.size());
  for(int i = 0; i < m.size(); i++) m[i].resize(A.size());

  for(int i = 0; i < A.size(); i++) m[i][A[i]]++;
  for(int i = 0; i < B.size(); i++) m[i][B[i]]++;

  fexp(m, E - 1, mod);
  int ans = 0;
  for(int i = 0; i < m.size(); i++)
    ans = (ans + m[D][i])%mod;
  return ans;
}

int main(){
  vector<int> A(3);
  vector<vector<long long>> m(A.size());
  for(int i = 0; i < m.size(); i++) m[i].resize(A.size());
  m[0][0] = 1, m[0][1] = 1;
  m[1][1] = 1, m[1][2] = 1;
  m[2][0] = 1, m[2][2] = 1;
  for(int i = 0; i < m.size(); i++){
    for(int j = 0; j < m.size(); j++)
      cout << m[i][j] << ' ';
    cout << endl;
  }
  fexp(m, 4, 1e9 + 7);
  for(int i = 0; i < m.size(); i++){
    for(int j = 0; j < m.size(); j++)
      cout << m[i][j] << ' ';
    cout << endl;
  }
  
  const int mod = 1e9 + 7;
  int ans = 0;
  for(int i = 0; i < m.size(); i++)
    ans = (ans + m[2][i])%mod;
  cout << ans << endl;
}
