#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<

typedef long long ll;

int main(){
  ll n, k, a, b, ans = 0;
  cin >> n >> k >> a >> b;
  if(k == 1) return cout << (n - 1)*a << endl, 0;
  
  while(1){
    int i = n/k*k;
    if(i == 0) break;
    ans += a*(n - i);
    n = i;
    if((n - n/k)*a >= b) 
      ans += b, n/=k;
    else
      ans += (n - n/k)*a, n/=k;
    //db(i _ n _ ans);
  }
  ans += (n - 1)*a;
  cout << ans << endl;
}
