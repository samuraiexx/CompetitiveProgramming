#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n;
  cin >> n;

  string a, b;
  cin >> a >> b;

  ll uu, zz, zu, uz;
  uu = zz = zu = uz = 0;

  for(int i = 0; i < n; i++){
    if(a[i] == '0')
      if(b[i] == '0')
        zz++;
      else zu++;
    else
      if(b[i] == '0') uz++;
      else uu++;
  }

  ll ans = 0;
  ans = uu*zz + uz*zz + uz*zu;

  cout << ans << endl;
}
