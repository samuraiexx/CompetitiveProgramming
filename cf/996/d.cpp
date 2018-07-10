#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 505;
ll bit[N];
int v[N];
int pos[N];

ll query(int a, int b){
  ll ans = 0;
  b--;
  for(; b > 0; b -= b&-b)
    ans += bit[b];

  for(; a > 0; a -= a&-a)
    ans -= bit[a];

  return ans;
}

void add(int p, int val){
  for(; p < N; p += p&-p)
    bit[p] += val;
}

int main(){
  int n;
  ll ans = 0;
  cin >> n;

  for(int i = 1; i <= 2*n; i++){
    cin >> v[i];
    pos[v[i]] = i;
    add(i, 1);
  }

  for(int i = 1; i <= 2*n; i++){
    if(pos[v[i]] == i) continue;
    ans += query(i, pos[v[i]]);
    add(pos[v[i]], -1);
  }

  cout << ans << endl;
}
