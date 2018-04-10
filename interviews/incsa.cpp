#include<bits/stdc++.h>
using namespace std;

int cntInc(vector<int> &A) {
  int n = A.size();
  long long ans = 0;
  const int mod = 1e9 + 7;
  for(int i = 0; i < n;){
    int j;
    for(j = i + 1; j < n and A[i - 1] < A[i]; j++)
    ans += (j - i)*(j - i - 1)/2 + (j - i);
    i = j;
    cout << ans << endl;
  }
  return ans%mod;
}


int main(){
  vector<int> v = {4, 5, 1, 2};
  cout << cntInc(v) << endl;
}
