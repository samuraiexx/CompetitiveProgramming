#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e6 + 5;

int criv[N];

int main(){
  vector<int> p;
  for(int i = 2; i < N; i++)
    if(!criv[i])
      for(int j = 2*i; j < N; j += i)
        criv[j] = i;

  for(int i = 2; i < N; i++)
    if(!criv[i]) p.pb(i);

  int x;
  cin >> x;
  
  int mn = 1e9;
  for(auto a : p)
    if(x%a == 0 and x != a){
      for(int i = x - a + 1; i <= x; i++)
        if(criv[i]){
          int z = criv[i];
          mn = min(mn, i - z + 1);
        }
    }

  cout << mn << endl;
}
