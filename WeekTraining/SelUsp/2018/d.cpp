#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e6 + 5;

struct Par{
  int x, y;
  char p;

  bool operator<(Par p) const{ return x < p.x; }
} pnt[N];

  bool cmp(Par a, Par b){ return a.y < b.y;}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  int tb = 0, tw = 0;
  for(int i = 0; i < n; i++){
    cin >> pnt[i].x >> pnt[i].y >> pnt[i].p;
    if(pnt[i].p == 'b') tb++;
    else tw++;
  }

  sort(pnt, pnt+n);
  int ans = max(tb, tw);

  int cntb = 0, cntw = 0;
  for(int i = 0; i < n; i++){
    auto p = pnt[i];

    if(p.p == 'b') cntb++;
    else cntw++;
    if(i < n and pnt[i + 1].x == p.x) continue;

    ans = max({ans, tb - cntb + cntw, tw - cntw + cntb});
  }

  sort(pnt, pnt+n, cmp);

  cntb = 0, cntw = 0;
  for(int i = 0; i < n; i++){
    auto p = pnt[i];
    if(p.p == 'b') cntb++;
    else cntw++;
    if(i < n and pnt[i + 1].y == p.y) continue;

    ans = max({ans, tb - cntb + cntw, tw - cntw + cntb});
  }

  cout << ans << '\n';
}
