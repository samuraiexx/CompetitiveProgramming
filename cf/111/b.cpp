#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << " , " << 
typedef long long ll;
const int N = 1e5 + 5;
int last[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    int x, y, ans = 0;
    cin >> x >> y;

    for(int j = 1; j*j <= x; j++)
      if(x%j == 0) {
        if(i - last[j] > y) ans++;
        last[j] = i;

        if(j*j != x)
          if(i - last[x/j] > y) ans++;
          last[x/j] = i;
      }

    cout << ans << '\n';
  }
}
