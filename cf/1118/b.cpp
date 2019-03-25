#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
int e[N], o[N], v[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> v[i];

  for(int i = 1; i <= n; i++)
    if(i&1) o[i/2] = v[i];
    else e[i/2] = v[i];

  //odd, even
  for(int i = 1; i <= n/2; i++)
    o[i] += o[i - 1], e[i] += e[i - 1];

  int ans = (o[n/2] - v[1] == e[n/2]);
  for(int i = 2; i <= n; i++){
    int os = o[(i - 2)/2] + e[n/2] - e[i/2];
    int es = e[(i - 1)/2] + o[n/2] - o[(i - 1)/2];
    ans += os == es;
  }

  cout << ans << endl;
}
