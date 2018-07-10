#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int ans[N];

struct point{
  int x, y;
  point(int x, int y):x(x), y(y) {}
  point():x(0), y(0) {}
  point operator+(point p){ return point(x + p.x, y + p.y); }
  point operator-(point p){ return point(x - p.x, y - p.y); }
  ll operator!(){ return x*(long long)x + y*(long long)y; }
} v[N];

int main(){
  int n;
  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> v[i].x >> v[i].y;

  int lst = 0;
  point sum;

  for(int i = 1; i < n; i++){
    int j = i;
    ll s1 = min(!(sum + v[j]), !(sum - v[j]));
    ll s2 = min(!(sum + v[lst]), !(sum - v[lst]));
    
    if(s1 > s2)
      swap(j, lst);

    s1 = !(sum + v[j]);
    s2 = !(sum - v[j]);

    if(s1 < s2) ans[j] = 1, sum = sum + v[j];
    else ans[j] = -1, sum = sum - v[j];
  }

  ll s1 = !(sum + v[lst]);
  ll s2 = !(sum - v[lst]);

  if(s1 < s2) ans[lst] = 1;
  else ans[lst] = -1;


  for(int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}
