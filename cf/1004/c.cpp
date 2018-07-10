#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int v[N];
int dif[N];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  set<int> s;
  for(int i = n - 1; i >= 0; i--){
    dif[i] += dif[i + 1];
    if(s.count(v[i])) continue;
    else s.insert(v[i]), dif[i]++;
  }
  s.clear();

  ll ans = 0;
  for(int i = 0; i < n; i++){
    if(s.count(v[i])) continue;
    else s.insert(v[i]), ans += dif[i + 1];
  }
  cout << ans << endl;

}
