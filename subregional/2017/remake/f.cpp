#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
int v[N];

int main(){
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  sort(v, v + n, greater<int>());
  cout << upper_bound(v, v + n, v[k - 1], greater<int>()) - v << endl;
}
