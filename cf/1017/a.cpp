#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  vector<pair<int, int>> v;

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    int sum = 0, s;
    for(int j = 0; j < 4; j++)
      cin >> s, sum += s;

    v.push_back({-sum, i});
  }

  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++){
    auto p = v[i];
    if(p.nd == 1) return cout << i + 1 << endl, 0;
  }
}
