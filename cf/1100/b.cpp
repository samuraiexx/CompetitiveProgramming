#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int amt[N], cnt[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n, m;
  cin >> m >> n;
  
  int r = 0;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;

    amt[cnt[x]++]++;
    if(amt[r] == m) r++, cout << 1;
    else cout << 0;
  }
  cout << endl;
}
