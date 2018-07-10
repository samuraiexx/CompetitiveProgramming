#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int t = a + b - c;
  if(t > n - 1 or c > b or c > a) cout << -1 << endl;
  else cout << n - t << endl;
}
