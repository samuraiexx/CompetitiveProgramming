#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 205;
int bed[N], tap[N];

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    memset(bed, 0, sizeof bed);
    cin >> n >> k;
    int t = 1;
    for(int i = 0, a; i < k; i++)
      cin >> a, bed[a - 1] = 1;

    bool ok = false;
    while(!ok){
      ok = true;
      for(int i = 0; i < n; i++)
        if(!bed[i]) ok = false;
      if(ok) break;

      t++;
      memset(tap, 0, sizeof tap);
      for(int i = 0; i < n; i++)
        if(bed[i]) tap[i] = tap[max(i - 1, 0)] = tap[min(n - 1, i + 1)] = 1;

      for(int i = 0; i < n; i++)
        bed[i] = tap[i];
    }

    cout << t << endl;
  }
}
