#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int par[N], sz[N], d[N];

pair<int, int> find(int a){
  if(par[a] == a) return {a, 0};
  auto p = find(par[a]);
  par[a] = p.st;
  d[a] += p.nd;

  return {par[a], d[a]};
}

void unite(int a, int b, int w){
  auto pa = find(a);
  auto pb = find(b);

  if(sz[pa.st] < sz[pb.st]) swap(a, b), swap(pa, pb), w = -w;

  d[pb.st] = -pb.nd - w + pa.nd;
  par[pb.st] = pa.st;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n, m;
  while(cin >> n >> m, n){
    for(int i = 1; i <= n; i++)
      par[i] = i, sz[i] = 1, d[i] = 0;

    while(m--){
      char c;
      cin >> c;
      if(c == '!'){
        int a, b, w;
        cin >> a >> b >> w;
        unite(a, b, w);
      }else{
        int a, b;
        cin >> a >> b;
        auto pa = find(a);
        auto pb = find(b);

        if(pa.st != pb.st) cout << "UNKNOWN\n";
        else cout << pa.nd - pb.nd << '\n';
      }
    }
  }
}
