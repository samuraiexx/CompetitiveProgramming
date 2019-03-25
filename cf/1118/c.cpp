#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
int ans[N][N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  
  map<int, int> cnt;
  int n;
  cin >> n;
  for(int i = 0, x; i < n*n; i++)
    cin >> x, cnt[x]++;

  int amt = n/2*(n/2);
  vector<int> ex;
  int solo;
  int k = 0;

  for(auto p : cnt){
    while(p.nd >= 4 and k < amt)
      ans[k/(n/2)][k%(n/2)] = p.st, k++, p.nd -= 4;
    while(p.nd >= 2) ex.pb(p.st), p.nd-=2;
    if(p.nd) solo = p.st;
  }

  if(k < amt or n&1 and ex.size() < n - 1)
    return cout << "No\n", 0;
  cout << "Yes\n";

  k = 0;
  vector<int> ans2(2*n - 1);
  if(n&1){
    for(int i = 0; i < n - 1; i++)
      ans2[i] = ans2[ans2.size() - i - 1] = ex[k++];
    ans2[n - 1] = solo;
  }


  k = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(n&1 and (i == n/2 or j == n/2)) cout << ans2[k++] << ' ';
      else {
        int i2 = i >= n/2 ? n - i - 1 : i;
        int j2 = j >= n/2 ? n - j - 1 : j;
        cout << ans[i2][j2] << ' ';
      }
    }
    cout << '\n';
  }
}
