#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 205;
char m[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
  int t;
  cin >> t;
  cout << t << endl;
  while(t--){
    memset(m, '#', sizeof m);
    string s;
    cin >> s;

    int x = N/2, y = N/2;
    int mnx = x, mny = y, mxx = x, mxy = y;
    int i = 0;

    m[x][y] = '.';
    for(auto c : s){
      if(c == 'R') i = (i + 1)%4;
      if(c == 'B') i = (i + 2)%4;
      if(c == 'L') i = (i + 3)%4;
      x += dx[i], y += dy[i];
      mnx = min(mnx, x), mny = min(mny, y);
      mxx = max(mxx, x), mxy = max(mxy, y);
      m[y][x] = '.';
    }
    mny--, mnx--, mxy++, mxx++;
    if(s[0] == 'F') mnx++;
    if(s[0] == 'R') mny++;
    if(s[0] == 'L') mxy--;
    if(s[0] == 'B') mxx--;
    cout << mxy - mny + 1 << ' ' << mxx - mnx + 1 << endl;
    for(int i = mny; i <= mxy; i++){
      for(int j = mnx; j <= mxx; j++)
        cout << m[i][j];
      cout << endl;
    }
  }
}
