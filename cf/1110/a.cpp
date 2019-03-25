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
  int b, k;
  cin >> b >> k;
  int ans = true;
  for(int i = 0; i < k; i++){
    int x;
    cin >> x;
    if(b&1 or i == k - 1)  ans = ans^(x&1);
  }

  cout << (ans ? "even" : "odd") << endl;
}
