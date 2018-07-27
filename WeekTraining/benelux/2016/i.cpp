#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 1e5;

int criv[N];

int main(){
  vector<int> p;
  for(int i = 2; i < N; i++){
    if(!criv[N]){
      p.pb(i);
      for(int j = i; j < N; j+=i)
        criv[j] = 1;
    }
  }

  int q;
  cin >> q;
  if(q == 1) return cout << "no" << endl, 0;
  bool x = 0;
  for(auto a : p)if(q%a == 0){
    while(q%a == 0) q /= a;
    x = 1;
    break;
  }
  if(x == 0 or q == 1) cout << "yes" << endl;
  else cout << "no" << endl;
}
