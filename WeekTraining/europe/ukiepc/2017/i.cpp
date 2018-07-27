#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n, h;
  cin >> n;
  vector<int> s;
  for(int i = 0, a; i < n; i++)
    cin >> a, s.pb(a);

  cin >> h;

  int mn = 1e9;
  int bst;
  for(auto a : s)
    if(mn > h%a) mn = h%a, bst = a;

  cout << bst << endl;
}
