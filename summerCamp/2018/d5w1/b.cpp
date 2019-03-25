#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

char dir[4][10] = {"NORTH", "SOUTH", "EAST", "WEST"};
char s[N];
int vis[100][100];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int x, y;

void dfs(int x, int y) {
    if(vis[x][y]) return;

    vis[x][y] = 1;

    for(int i=0; i<4; i++) {
        x += dx[i];
        y += dy[i];
        if(!vis[x][y]) {
            printf("%s\n", dir[i]);
            fflush(stdout);
            scanf("%s", s);
            if(strcmp(s, "BLOCKED")) {
                dfs(x, y);
                printf("%s\n", dir[i^1]);
                fflush(stdout);
                scanf("%s", s);
            }
            else vis[x][y] = 1;
        }
        x -= dx[i];
        y -= dy[i];
    }
}

int main(){
    x = 40, y = 40;
    dfs(40, 40);
    printf("DONE\n");
}
