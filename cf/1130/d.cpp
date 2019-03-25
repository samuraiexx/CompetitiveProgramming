#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
vector<pair<int, int>> v;
const int N = 2e5 + 5;
int amt[N], mn[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  memset(mn, 0x3f, sizeof mn);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    amt[a]++;
    mn[a] = min(mn[a], (b - a + n)%n);
  }

  for(int i = 0; i < n; i++){
    int ans = 0;
    for(int j = 0; j < n; j++){
    }
  }
}
