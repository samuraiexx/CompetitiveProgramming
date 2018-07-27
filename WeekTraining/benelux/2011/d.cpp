#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;
const int INF = 0x3f3f3f3f;
bool l[N];
int n, d;

void flip(int x){
  for(int i = max(0, x - d); i <= min(n - 1, x + d); i++)
    l[i] ^= 1;
}

int backtracking(int x){
  int amt = INF;
  bool f = false;

  if(x == n){
    for(int i = max(n - d, 0); i < n; i++)
      if(l[i]) return INF;
    return 0;
  }

  if(x < d){
    amt = backtracking(x + 1);
    flip(x), f = true;
  } else if(l[x - d])
    flip(x), f = true;
  
  amt = min(amt, backtracking(x + 1) + f);
  if(f) flip(x);
  return min(INF, amt);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cin >> n >> d;
    for(int i = 0; i < n; i++)
      cin >> l[i];

    int amt = backtracking(0);
    if(amt == INF) cout << "impossible" << endl;
    else cout << amt << endl;
  }
}
