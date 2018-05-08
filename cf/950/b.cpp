#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int b1[N];
int b2[N];

int main(){
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++) cin >> b1[i];
  for(int i = 0; i < m; i++) cin >> b2[i];

  int ans = 0;
  int i = 0, j = 0;
  int sumi = 0, sumj = 0;
  while(i < n and j < m){
    if(sumi > sumj) sumj += b2[j++];
    else sumi += b1[i++];

    if(sumj == sumi) ans++, sumj = sumi = 0;
  }
  if(i < n or j < m) ans++;

  cout << ans << endl;
}
