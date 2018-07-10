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
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 0; i < n; i++) cin >> v[i], v[i] *= 10, sum += v[i];
  sort(v, v + n);

  int ans = 0;
  for(int i = 0; i < n and sum < 45*n; i++){
    ans++;
    sum = sum + 50 - v[i];
  }
  cout << ans << endl;
}
