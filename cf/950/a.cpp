#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int l, r, a;
  cin >> l >> r >> a;
  if(l > r) swap(l, r);
  if(a >= r - l) l = r, a -= r-l;
  else l += a, a = 0;

  l += a/2, r += a/2;

  cout << 2*min(l, r) << endl;
}
