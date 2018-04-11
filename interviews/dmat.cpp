#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
using namespace std;


int fexp(long long a, int b, const int mod){
  long long ans = 1;
  while(b)
    if(b&1) ans = (ans*a)%mod, b--;
    else a = (a*a)%mod, b /= 2;
  return (int)ans;
}

int cntMatrix(vector<int> &A) {
  int n = A.size();
  const int mod = 1e9 + 7;
  vector<bool> works(n + 1);
  vector<int> criv(n + 1);
  vector<long long> fac(n + 1);

  for(int i = 2; i <= n; i++)
    if(!criv[n])
      for(int j = i; j <= n; j += i) criv[j] = i;

  fac[0] = 1;
  for(int i = 1; i < fac.size(); i++)
    fac[i] = (fac[i - 1]*i)%mod;

  set<int> divs;
  for(int i = 2; i <= n; i++) if(n%i == 0)
    divs.insert(i);

  vector<int> sizes;

  for(auto x : divs){
    bool ok = true;
    if(criv[x] == x){
      for(int i = 0; i < n; i++)
        for(int j = 0; j < x - 1; j++, i++)
          if(A[i] > A[i + 1]) ok = false;
      works[x] = ok;
    } else {
      if(!works[criv[x]]) continue;
      for(int i = criv[x]; i < n; i += criv[x])
        if(A[i] < A[i - 1]) ok = false;
    }
    if(ok) sizes.push_back(x);
  }

  long long ans = 1;
  for(auto x : sizes)
    ans = (ans + fexp(fac[x], n/x, mod))%mod;

  return (int)ans;
}


int main(){
  vector<int> a = {1, 3, 2, 4};
  cout << cntMatrix(a) << endl;
}
