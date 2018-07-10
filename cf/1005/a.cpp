#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n;
  vector<int> ans;
  cin >> n;

  int prev;
  cin >> prev;
  for(int i = 1; i < n; i++){
    int x;
    cin >> x;
    if(x == 1)
      ans.pb(prev);
    prev = x;
  }
  ans.pb(prev);

  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] << ' ';
  cout << endl;
}
