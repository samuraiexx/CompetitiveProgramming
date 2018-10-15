#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;
int n;
int v[N];
int dp[N][N];

int grundy(int a, int b){
  if(dp[a][b] != -1) return dp[a][b];
  bool w = true;

  if(a == b) return v[a] == 1;
  if(v[a] > v[a + 1]) w |= grundy(a + 1, b);
  if(v[b] > v[b - 1]) w |= grundy(a, b - 1);

  for(int i = a + 1; i < b; i++)
    w |= grundy(a, i - 1) | grundy(i + 1, b);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cin >> n;

    for(int i = 0, x; i < n; i++)
      cin >> v[i];
  }
}
