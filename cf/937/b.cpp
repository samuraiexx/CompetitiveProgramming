#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 1e5 + 5;
int pr[N];
vector<int> primes;

int main(){
    int p, y;
    cin >> p >> y;
    int n = min(p, (int)1e5);
    for(int i = 2; i <= n; i++)
      if(!pr[N]){
        primes.pb(i);
        for(int j = i; j <= n; j += i)
          pr[j] = 1;
      }

    int ans = -1;
    while(y > p){
      bool isp = 1;
      for(auto x : primes) if(y%x == 0) { isp = 0; break; }
      if(isp) { ans = y; break; }
      else y--;
    }
    
    cout << ans << endl;

