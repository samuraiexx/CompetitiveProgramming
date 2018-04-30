#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;

bool prime[N];

int main(){
  int n;
  cin >> n;

  if(n <= 2) cout << 1 << endl;
  else cout << 2 << endl;

  for(int i = 2; i <= n+1; i++){
    if(prime[i]) cout << 2 << ' ';
    else cout << 1 << ' ';

    if(!prime[i])
      for(int j = i*2; j <= n+1; j+=i)
        prime[j] = true;
  }
  cout << endl;
}
