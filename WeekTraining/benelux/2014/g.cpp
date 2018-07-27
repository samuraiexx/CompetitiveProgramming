#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    double mx = -1e9;
    int mxi;
    cin >> n;
    for(int i = 0; i < n; i++){
      int a, b, c;
      cin >> a >> b >> c;
      double d = (b*b + 4*a*c)/(double)(4*a);
      if(d > mx) mx = d, mxi = i + 1;
    }
    cout << mxi << endl;
  }
}
