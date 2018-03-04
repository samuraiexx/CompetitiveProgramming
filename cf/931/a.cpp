#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " << 

ll sumx(ll x, ll y){
  ll ret = 0;
  ll j = 1;
  for(ll i = x; i < y; i++, j++)
    ret += j;
  return ret;
}

int main(){
  ll a, b;
  cin >> a >> b;
  if(a > b) swap(a, b);
  ll mid = (a + b)/2;
  cout << sumx(a, mid) + sumx(mid, b) << endl;
}
