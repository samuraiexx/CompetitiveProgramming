#include<bits/stdc++.h>
using namespace std;

int solvedp(int A, int B, vector<vector<int>> &memoize, int mod){
  cout << A << ' ' << B << endl;
  if(B > A*9 or B < 0) return 0;
  if(A == 1) return 1;
  if(memoize[A][B]) return memoize[A][B];
  long long sum = 0;
  for(int i = 0; i <= 9; i++)
    sum = (sum + solvedp(A - 1, B - i, memoize, mod))%mod;
  return memoize[A][B] = sum;
}
int solve(int A, int B) {
  vector<vector<int>> memoize(1e3);
  for(auto &v : memoize) v.resize(1e4);

  long long ans = solvedp(A, B, memoize, 1e9 + 7);
  ans = ans + (int)1e9 + 7 - solvedp(A - 1, B, memoize, 1e9 + 7);
  ans = ans%((int)1e9 + 7);
  return ans;
}


int main(){
  cout << solve(3, 4) << endl;
}
