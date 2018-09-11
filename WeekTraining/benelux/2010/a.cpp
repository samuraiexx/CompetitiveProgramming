#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int v[N], u[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> v[i];
    for(int i = 0; i < n; i++)
      cin >> u[i];

    set<int> sv, su;
    int last = 0;

    for(int i = 0; i < n; i++){
      if(su.count(v[i])) su.erase(v[i]);
      else sv.insert(v[i]);

      if(sv.count(u[i])) sv.erase(u[i]);
      else su.insert(u[i]);

      if(sv.size() == 0 and su.size() == 0)
        cout << last + 1 << '-' << i + 1 << ' ', last = i + 1;
    }
    cout << '\n';
  }
}
