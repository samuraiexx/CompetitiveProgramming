#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e6 + 5;
int sieve[N];
int v[N], acc[N];

void fat(int x, int* v){
  while(sieve[x]){
    int k = sieve[x];
    int amt = 0;
    while(x%k == 0) x /= k, amt++;

    v[k] = max(v[k], amt);
  }
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  for(int i = 2; i < N; i++) if(!sieve[i])
    for(int j = i; j < N; j += i)
      sieve[j] = i;

  int n, k;
  cin >> n >> k;

  fat(k, v);

  for(int i = 0; i < n; i++){
    int y;
    cin >> y;
    fat(y, acc);
  }

  for(int i = 0; i <= k; i++)
    if(v[i] > acc[i]) return cout << "No\n", 0;

  cout << "Yes\n";
}
