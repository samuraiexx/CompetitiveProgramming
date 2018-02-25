#include<bits/stdc++.h>
using namespace std;
const long long N = 100;
long long l[N], l2[N];

int main(){
  long long n, m, ans;
  ans = 1e18 + 5;
  cin >> n >> m;
  for(long long i = 0; i < n; i++) cin >> l[i];
  for(long long i = 0; i < m; i++) cin >> l2[i];
  sort(l, l+n), sort(l2, l2 + m);

  for(int k = 0; k < n; k++){
  vector<long long> asd;
    for(int i = 0; i < n; i++)if(i != k)
      for(int j = 0; j < m; j++)
        asd.push_back(l[i]*l2[j]);

    sort(asd.begin(), asd.end());
    ans = min(ans, asd.back());
  }

  cout << ans << endl;
}
