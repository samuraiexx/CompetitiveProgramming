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

  if(n <= 5) cout << -1 << endl;
  else{
    cout << 1 << ' ' << 2 << endl;
    cout << 2 << ' ' << 3 << endl;
    cout << 2 << ' ' << 4 << endl;
    for(int i = 5; i <= n; i++)
      cout << 1 << ' ' << i << endl;
  }

  for(int i = 2; i <= n; i++)
    cout << i - 1 << ' ' << i << endl;
}
