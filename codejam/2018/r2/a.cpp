#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

const int N = 1e5 + 5;


struct Perc{
  int x, y;
  bool operator<(const Perc &b) const{
    if(x*2 < y and b.x*2 >= b.y) return true;
    if(x*2 >= y and b.x*2 < b.y) return false;
    return x > b.x;
  }
};

int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    int ans = 0;
    int n, m, cnt = 0;
    cin >> n >> m;

    multiset<Perc> v;
    for(int i = 0; i < m; i++){
      int a;
      cin >> a;
      v.insert({100*a%n, n});
      ans += 100*a/n;
      cnt += a;
    }

    cnt = n - cnt;
    while(cnt--){
      auto it = v.begin();
      auto x = *it;
      if(2*x.x >= x.y) {cnt++; break; }
      v.erase(it);
      x.x += 100;
      v.insert(x);
    }

    while(cnt > 0){
      Perc x = {0, n};
      while(cnt and 2*x.x < x.y) x.x+=100, cnt--;
      v.insert(x);
    }

    for(auto x : v){
      int add = 0;
      add += x.x/x.y;
      int x1 = x.x%x.y;
      if(x.y <= 2*x1) add++;
      ans += add;
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
