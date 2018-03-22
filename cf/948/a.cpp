#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
char m[505][505];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){
  int r, c;
  vector<pair<int, int>> w;
  cin >> r >> c;
  for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++){
      cin >> m[i][j];
      if(m[i][j] == 'W')
        w.pb({i, j});
    }

  for(auto p : w){
    for(int i = 0; i < 4; i++){
      int x = p.st + dx[i], y = p.nd + dy[i];
      if(m[x][y] == 'S') return cout << "NO" << endl, 0;
      if(m[x][y] == 'W') continue;
      m[x][y] = 'D';
    }
  }

  cout << "YES" << endl;
  for(int i = 1; i <= r; i++){
    for(int j = 1; j <= c; j++)
      cout << m[i][j];
    cout << endl;
  }

}
