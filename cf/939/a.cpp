#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<
typedef long long ll;
const int N = 5e3 + 5;
int l[N];


int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> l[i];
  for(int i = 1; i <= n; i++) if(l[l[l[i]]] == i and l[l[i]] != i) return cout << "YES" << endl, 0;
  cout << "NO" << endl;
}
