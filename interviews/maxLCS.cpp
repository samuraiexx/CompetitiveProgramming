#include<bits/stdc++.h>
using namespace std;

int LCS(string &A, string &B, int i, int j, vector<vector<int>> &lcs){
  if(i == A.size() or j == B.size()) return 0;
  if(lcs[i][j] != -1) return lcs[i][j];
  if(A[i] == B[j]) return lcs[i][j] = 1 + LCS(A, B, i + 1, j + 1, lcs);
  return lcs[i][j] = max(LCS(A, B, i + 1, j, lcs), LCS(A, B, i, j + 1, lcs));
}

vector<int> maxLCS(string A) {
  int n = A.size();
  vector<vector<int>> lcs(n);
  string B = A;
  reverse(B.begin(), B.end());
  cout << A << ' ' << B << endl;
  for(auto &v : lcs) v.resize(n, -1);

  LCS(A, B, 0, 0, lcs);
  int mx = -1, pos;
  for(int i = 0; i < n; i++)
    if(mx < lcs[i][n - i - 2])
      pos = i, mx = lcs[i][n - i - 2];

  for(auto &v : lcs){
    for(auto x : v)
      cout << x << ' ';
    cout << endl;
  }

  return vector<int>({pos, mx});
}


int main(){
  string s = "abba";
  cout << maxLCS(s)[0] << endl;
}
