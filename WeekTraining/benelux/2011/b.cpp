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
  int t;
  cin >> t;
  while(t--){
    int h, w, d;
    pair<int, int> bg;
    cin >> h >> w >> d;

    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        cin >> m[i][j];
        if(m[i][j] == 'S') bg = {i, j};
      }
    }

    priority_queue<tuple<int, int, int>,
                   vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>> q;

    q.push({0, bg.st, bg.nd});

    while(q.size()){
      int wg, x, y;
      tie(wg, x, y) = q.top(); q.pop();

      if(x < 0 or x >= h or y < 0 or y >= w){
        cout << wg << endl;
        break;
      }
      if(m[x][y] == '#') continue;
      m[x][y] = '#';

      for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nw = wg + 1;
        if(m[nx][ny] == '@') nw += d;
        q.push({nw, nx, ny});
      }
    }
  }
}
