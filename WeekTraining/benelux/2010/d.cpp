#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int k = (n - (n - 1)/3);
    cout << (n - (n/2) + k/2 + (k&1)*(n&1)) << '\n';
  }
}
