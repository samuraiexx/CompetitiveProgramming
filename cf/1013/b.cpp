#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int v[N];

int main(){
  int n, x;
  map<int, int> org, aft;
  cin >> n >> x;
  for(int i = 0; i < n; i++){
    cin >> v[i];

    if(org.count(v[i]))
        return cout << 0 << endl, 0;
    org[v[i]]++;
  }

  for(int i = 0; i < n; i++)
    aft[v[i]&x]++;

  for(int i = 0; i < n; i++)
    if(aft[v[i]] == 1 and (v[i]&x) != v[i] or aft[v[i]] > 1)
      return cout << 1 << endl, 0;

  for(auto p : aft)
    if(p.nd > 1)
      return cout << 2 << endl, 0;

  cout << -1 << endl;
}
