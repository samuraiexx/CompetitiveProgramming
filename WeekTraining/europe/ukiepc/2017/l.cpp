#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e6 + 5;

int dp[N], lis;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

struct point{
  int x, y;
  point(int x, int y):x(x), y(y){}
  point(){}

  ll operator!(){ return (ll)x*(ll)x + (ll)y*(ll)y; }
  point operator~(){
    int d = abs(gcd(x, y));
    return point(x/d, y/d); 
  }
  point operator-(point p){ return point(x - p.x, y - p.y); }

  bool operator<(const point p)const { return x == p.x ? y < p.y : x < p.x; }
};

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  map<point, vector<pair<ll, int>>> lz;

  point t;
  cin >> t.x >> t.y;

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    point p;
    int h;
    cin >> p.x >> p.y >> h;
    lz[~(p - t)].pb({!(p - t), h});
  }

  int ans = 0;
  for(auto p : lz){
    auto &v = p.nd;
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size() + 1; i++)
      dp[i] = 0x3f3f3f3f;

    lis = 0;
    for(auto x : v){
      int j = lower_bound(dp, dp+lis, x.nd) - dp;
      dp[j] = min(dp[j], x.nd);
      lis = max(lis, j+1);
    }
    ans += lis;
  }

  cout << ans << '\n';
}
