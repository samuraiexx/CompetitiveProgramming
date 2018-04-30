#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  string st, nd;
  int n;
  cin >> st >> nd >> n;

  cout << st << ' ' << nd << endl;
  for(int i = 0; i < n; i++){
    string m, r;
    cin >> m >> r;
    if(st == m) st = r;
    else nd = r;

    cout << st << ' ' << nd << endl;
  }
}
