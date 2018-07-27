#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;

int all1[N][N];
int all2[N][N];

bool inout[N];

int main(){
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;

    auto p = all1;
    if(all1[a][b]){ 
      p = all2, inout[i] = true;
      if(all2[a][b]) return cout << "impossible\n", 0;
    }

    for(int i = a + 1; i%n != b; i++)
      for(int j = b + 1; j%n != a; j++)
        p[i%n][j%n] = true,
        p[j%n][i%n] = true;
  }

  for(int i = 0; i < m; i++)
    cout << (inout[i] ? 'o' : 'i');
  cout << endl;
}
