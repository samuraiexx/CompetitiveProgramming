#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 1e5 + 5;
bool arena[N];
bool posi[N];

int main(){
  string s;
  cin >> s;
  int n = s.size(), ans = 0;
  bool ok = 1;
  for(int i = 0; i < n; i++)
    if(s[i] == 'R') arena[i] = 1;
    else ok = 0;

  if(ok) return cout << n - 1 << endl, 0;

  set<int> div;

  for(int i = 2; i < n; i++) if(n%i == 0) div.insert(i);

  for(auto i : div){
    if(n%i != 0 or posi[i]) continue;
    bool ok = 0;
    for(int j = 0; !ok and j < i; j++){
      for(int k = j; k < n; k += i)
        if(!arena[k]) break;
        else if(k + i >= n) ok = 1;
    }
    if(ok) for(int k = i; k <= n; k += i)  posi[k] = 1;
  }

  for(int i = 0; i < n; i++) ans += posi[i];
  cout << ans << endl;
}
