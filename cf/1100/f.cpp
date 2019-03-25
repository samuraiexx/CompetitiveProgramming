#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int M = 20;
const int N = 1 << M;
int n;
int c[N];
vector<int> sparse[N][M];

vector<int> merge(vector<int> &b1, vector<int> &b2){
  vector<int> ans, v;
  for(auto x : b1) v.pb(x);
  for(auto x : b2) v.pb(x);
  
  int k = 0;
  for(int i = M - 1; i >= 0 and k < v.size(); i--){
    int bit = 1 << i;

    for(int i = k; i < v.size(); i++) if(v[i]&bit){
      swap(v[i], v[k]);
      break;
    }

    if(!(v[k]&bit)) continue;

    for(int i = k + 1; i < v.size(); i++)
      if(v[i]&bit) v[i] ^= v[k];

    ans.pb(v[k++]);
  }
  return ans;
}

void build() {
  for(int i = 0; i < n; i++)
    sparse[i][0].pb(c[i]);

  for(int j = 1; j < M; j++)
    for(int i = 0; i < n; i++)
      sparse[i][j] = 
        i + (1 << j - 1) < n
        ? merge(sparse[i][j - 1], sparse[i + (1 << j - 1)][j - 1]) 
        : sparse[i][j - 1];
}

void print(vector<int> v){
  for(auto x : v)
    cout << x << ' ';
  cout << endl;
}

vector<int> query(int a, int b){
  int pot = 32 - __builtin_clz(b - a) - 1;
  return merge(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> c[i];

  build();

  int q;
  cin >> q;

  while(q--){
    int a, b;
    cin >> a >> b;

    auto v = query(a - 1, b - 1);

    int ans = 0;
    for(auto x : v)
      if((ans^x) > ans) ans ^= x;

    cout << ans << '\n';
  }
}
