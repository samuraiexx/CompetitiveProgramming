#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<
const int N = 105;
int x[N];

typedef long long ll;

int main(){
  int n, d;
  cin >> n >> d;
  int mn = 0x3f3f3f3f;
  for(int i = 0; i < n; i++) cin >> x[i];
  sort(x, x + n);
  for(int i = 0; i < n; i++){
    for(int j = n - 1; j >= i; j--){
      if(x[j] - x[i] <= d) mn = min(mn, n - (j - i + 1));
    }
  }
  cout << mn << endl;
}
