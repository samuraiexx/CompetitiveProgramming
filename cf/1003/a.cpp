#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;
int v[N], cnt[N];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i], cnt[v[i]]++;

  int ans = 0;
  for(int i = 0; i < N; i++)
    ans = max(ans, cnt[i]);

  cout << ans << endl;
}
