#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " << 

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  if(a > b) swap(a, b);

  int x;
  for(int i = 0; ; i++)
    if((1 << i) & n){ x = i; break; }

  if(a <= n/2 and b > n/2)
    return cout << "Final!" << endl, 0;

  while(1){
    if(a <= n/2 and b > n/2) break;
    if(a > n/2) a -= n/2;
    if(b > n/2) b -= n/2;

    n /= 2;
    x--;
  }

  cout << x << endl;
}
