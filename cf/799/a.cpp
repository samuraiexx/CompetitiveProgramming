#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n, t, k, d;
  cin >> n >> t >> k >> d;

  cout << ((((n + k - 1)/k - 1)*t > d) ? "YES" : "NO") << endl;
}
