#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef long long ld;

const int N=2e2+5;
const int INF=0x3f3f3f3f;

int dx[] = {-1, +1, +0, +0};
int dy[] = {+0, +0, -1, +1};

int h[N][N], grid[N][N], vis[N][N];

int max_x, max_y, max_z, ans;
int b1, b2;

bool check(int x, int y){ return x > 0 and y > 0 and x <= b1 and y <= b2 ; }

void dfs(int x, int y){
    vis[x][y] = 1;
    for(int i=0;i<4;i++){
        int xn = x + dx[i];
        int yn = y + dy[i];
        if(grid[xn][yn] and !vis[xn][yn] and check(xn, yn)) dfs(xn, yn);
    }
}

int main(){
    int r, c;
    scanf("%d %d", &r, &c);

    for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) scanf("%d", &h[i][j]), max_z = max(max_z, h[i][j]);

    max_x = r; max_y = c;

    //vista de cima
    
    for(int z=0;z<=max_z;z++){
        memset(grid, 0, sizeof grid);
        memset(vis, 0, sizeof vis);

        for(int x=1; x<=max_x; x++) for(int y=1; y<=max_y; y++) if(h[x][y] == z) grid[x][y] = 1;

        b1 = max_x, b2 = max_y;
        for(int x=1; x<=max_x; x++) for(int y=1; y<=max_y; y++) if(!vis[x][y] and grid[x][y]) ans++, dfs(x,y);
    }

    //vista lateral esq
    for(int z=1;z<=max_x;z++){
        memset(grid, 0, sizeof grid);
        memset(vis, 0, sizeof vis);

        for(int y=1; y<=max_z; y++) for(int x=1; x<=max_y; x++) if(h[z][x] >= y and y > h[z+1][x]) grid[x][y] = 1;

        b1 = max_y, b2 = max_z;
        for(int x=1; x<=max_y; x++) for(int y=1; y<=max_z; y++) if(!vis[x][y] and grid[x][y]) ans++, dfs(x,y);
    }

    //vista lateral dir

    for(int z=1;z<=max_x;z++){
        memset(grid, 0, sizeof grid);
        memset(vis, 0, sizeof vis);

        for(int y=1; y<=max_z; y++) for(int x=1; x<=max_y; x++) if(h[z][x] >= y and y > h[z-1][x]) grid[x][y] = 1;

        b1 = max_y, b2 = max_z;
        for(int x=1; x<=max_y; x++) for(int y=1; y<=max_z; y++) if(!vis[x][y] and grid[x][y]) ans++, dfs(x,y);
    }

    //vista de frente

    for(int z=1;z<=max_y;z++){
        memset(grid, 0, sizeof grid);
        memset(vis, 0, sizeof vis);

        for(int y=1; y<=max_z; y++) for(int x=1; x<=max_x; x++) if(h[x][z] >= y and y > h[x][z+1]) grid[x][y] = 1;

        b1 = max_x, b2 = max_z;
        for(int x=1; x<=max_x; x++) for(int y=1; y<=max_z; y++) if(!vis[x][y] and grid[x][y]) ans++, dfs(x,y);
    }

    //vista de trás

    for(int z=1;z<=max_y;z++){
        memset(grid, 0, sizeof grid);
        memset(vis, 0, sizeof vis);

        for(int y=1; y<=max_z; y++) for(int x=1; x<=max_x; x++) if(h[x][z] >= y and y > h[x][z-1]) grid[x][y] = 1;

        b1 = max_x, b2 = max_z;
        for(int x=1; x<=max_x; x++) for(int y=1; y<=max_z; y++) if(!vis[x][y] and grid[x][y]) ans++, dfs(x,y);
    }

    printf("%d\n", ans + 1);

    return 0;
}
