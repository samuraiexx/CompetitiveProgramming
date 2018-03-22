#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 3e4 + 5;
int n, t;

int adj[N];

int main(){
  cin >> n >> t;
  for(int i = 1; i < n; i++)
    cin >> adj[i], adj[i] += i;

  int x = 1;
  while(x != t and x != n)
    x = adj[x];

  if(x == t) cout << "YES" << endl;
  else cout << "NO" << endl;
}
