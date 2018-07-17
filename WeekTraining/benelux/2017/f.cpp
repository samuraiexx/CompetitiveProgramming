#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
const int N = 1e4 + 5;
int v[N];

int main(){
  int n;
  cin >> n;
  int p1 = 0, p2 = 0;
  for(int i = 0; i < n; i++)
    cin >> v[i];

  for(int i = 0; i < n; i++){
    int mx = 0;
    int p = 0;
    for(int i = 0; i < n; i++)
      if(mx < v[i]) mx = v[i], p = i;

    if(i%2 == 0) p1 += mx;
    else p2 += mx;
    
    v[p] = 0;
  }

  cout << p1 << ' ' << p2 << endl;
      

}
