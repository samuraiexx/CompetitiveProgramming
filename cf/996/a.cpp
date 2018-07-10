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
  int ans = 0;
  cin >> n;

  vector<int> bills({100, 20, 10, 5, 1});
  for(auto b : bills)
    while(n >= b) ans++, n -= b;

  cout << ans << endl;
}
