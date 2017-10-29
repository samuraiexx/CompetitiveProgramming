#include<bits/stdc++.h>
using namespace std;

#define px first
#define py second

const int N = 1e3 + 2;

bool room[N][N];
int vis[N][N];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            room[i][j] = c == '#';
        }
   
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2; 
    if(x1 == x2 && y1 == y2) return cout << 0 << endl, 0;
    queue<pair<int, int>> q;
    q.push({x1, y1});
    memset(vis, -1, sizeof(vis));
    vis[x1][y1] = 0;

    while(q.size()){
        auto p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
            for(int j = 1; j <= k; j++){
                int x = p.px + dx[i]*j;
                int y = p.py + dy[i]*j;
                if(x > n || x <= 0 || y > m || y <= 0 || room[x][y]) break;
                if(vis[x][y] != -1) continue;

                vis[x][y] = vis[p.px][p.py] + 1;
                if(x == x2 && y == y2) return cout << vis[x][y] << endl, 0;
                q.push({x, y});
            }
    }
    cout << "-1" << endl;
    return 0;
}
