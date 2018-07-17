#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 5e3;

int s[N], p[N], r[N], ord[N], ans[N];
bool rtd[N];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> s[i];
  for(int i = 0; i < n; i++) ord[i] = i;
  for(int i = 0; i < m; i++) cin >> p[i];
  for(int i = 0; i < m; i++) cin >> r[i];

  sort(ord, ord + n, [](int i, int j) { return s[i] > s[j]; });
  
  for(int i = 0; i < n; i++){
    int mn = 1e9;
    int bst;
    for(int j = 0; j < m; j++)
      if(!rtd[j] and p[j] >= s[ord[i]] and r[j] < mn)
        mn = r[j], bst = j;
    if(mn == 1e9) return cout << "impossible" << endl, 0;
    rtd[bst] = true;
    ans[ord[i]] = bst;
  }

  for(int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
  cout << endl;
}
