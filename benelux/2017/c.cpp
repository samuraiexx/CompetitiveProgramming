#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 5e5 + 5;
int v[N];

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
  int n;
  cin >> n;
  set<int> gcds;
  for(int i = 0; i < n; i++) cin >> v[i];

  for(int i = 0; i < n; i++){
    ll gc = v[i];
    gcds.insert(gc);
    for(int j = i + 1; j < n and gc != 1; j++)
      gc = gcd(gc, v[j]), gcds.insert(gc);
  }

  cout << gcds.size() << endl;
}
