#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " << 

int main(){
  int n, mn = 1e9, mx = -1e9;
  map<int, int> m;
  cin >> n;
  for(int i = 0, a; i < n; i++)
    cin >> a, m[a]++, mn = min(mn, a), mx = max(mx, a);

  int cv = 0;
  if(mn != mx and mx != mn + 1){
    int md = (mx + mn)/2;

    int amt1 = m[md]/2;
    int amt2 = min(m[mn], m[mx]);
    if(amt1 >= amt2) {
      cv = amt1;
      m[md] -= 2*amt1;
      m[mn] += amt1, m[mx] += amt1;
    } else {
      cv = amt2;
      m[md] += 2*amt2;
      m[mn] -= amt2, m[mx] -= amt2;
    }
  }

  cout << n - 2*cv << endl;

  for(auto p : m)
    for(int i = 0; i < p.nd; i++)
      cout << p.st << ' ';

  cout << endl;
  return 0;
}
