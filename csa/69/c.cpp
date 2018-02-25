#include<bits/stdc++.h>
using namespace std;
const int N = 3e3;
int dp[N][N];
string s;

int dpf(int i, int j){
  if(dp[i][j]) return dp[i][j];
  return dp[i][j] = dp[i + 1][j - 1] + (s[i] != '(') + (s[j] != ')');
}

int main(){
  cin >> s;
  
}
