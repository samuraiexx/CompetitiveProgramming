#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
bool m[4][200];

bool ok(int x){
  for(int i = 1; i <= 3; i++)
    for(int j = x - 1; j <= x + 1; j++)
      if(!m[i][j]) return false;
  return true;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    memset(m, 0, sizeof m);
    int x = -1, y = -1;
    int a;
    cin >> a;
    int p = 2;
    while(x != 0 and y != 0){
      cout << 2 << ' ' << p << endl;
      cin >> x >> y;
      m[x][y] = true;
      if(ok(p)) p += 3;
    }
  }
}
