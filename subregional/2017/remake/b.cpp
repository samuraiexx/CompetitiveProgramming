#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 3e6;
int v[N];

map<int, int> lst;

int main(){
  int n, t, x, y;
  cin >> n >> t >> v[0] >> x >> y;

  vector<int> tv;
  for(int i = 0, a; i < t; i++)
    cin >> a, tv.pb(a);

  for(int i = 1; i < N; i++){
    bool b = 0;
    for(auto x : tv)
      b ^= (v[i - 1] >> x)&1;
      
    v[i] = (v[i - 1] >> 1) + (b << n - 1);
  }

  v[0] = v[0]%x;
  for(int i = 1; i < N; i++)
    v[i] = (v[i] + v[i - 1])%x;

  lst[0] = 0;
  if(v[y - 1] == 0) return cout << 0 << ' ' << y - 1 << endl, 0;

  for(int i = 0; i + y < N; i++){
    int sum = v[i + y];

    if(!lst.count(v[i]))
      lst[v[i]] = i + 1;

    if(lst.count(sum))
      return cout << lst[sum] << ' ' << i + y << endl, 0;
  }
}
