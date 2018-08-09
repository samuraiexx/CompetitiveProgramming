#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
ll v[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> v[i];

    sort(v, v + n);

    ll lim = 0;
    for(int i = 0; i < n; i++)
      if(v[i] <= lim + 1) lim += v[i];
      else break;

    cout << lim + 1 << '\n';
  }
}
