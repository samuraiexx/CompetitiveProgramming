#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;

bool sieve[N];

bool is_prime(int n){
  if(n < N) 
    return !sieve[n];

  for(int i = 2; i*i <= n; i++)
    if(n%i == 0) return false;
  return true;
}

int main(){
  for(int i = 2; i < N; i++)
    if(!sieve[i])
      for(int j = 2*i; j < N; j += i)
        sieve[j] = true;

  int n;
  cin >> n;
  int m = 0;

  while(!is_prime(n)){
    n--, m++;
  }

  vector<int> ans;
  ans.push_back(n);

  sieve[0] = 1;
  if(is_prime(m)) ans.push_back(m);
  else{
    for(int i = 2; i <= m; i++)
      if(is_prime(i) and is_prime(m - i)){
        ans.push_back(i), ans.push_back(m - i);
        break;
      }
  }

  cout << ans.size() << endl;
  for(auto x : ans)
    cout << x << ' ';
  cout << endl;
}

