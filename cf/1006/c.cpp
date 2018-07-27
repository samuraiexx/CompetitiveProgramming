#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const ll N = 2e5 + 5;
ll v[N];

int main(){
  ll n;
  cin >> n;
  for(ll i = 0; i < n; i++)
    cin >> v[i];

  ll i = 0, j = n - 1;

  ll ans = 0;
  ll sum1 = 0, sum3 = 0;
  while(i <= j){
    if(sum1 < sum3) sum1 += v[i++];
    else sum3 += v[j--];

    if(sum1 == sum3) ans = max(ans, sum1);
  }

  cout << ans << endl;
}
