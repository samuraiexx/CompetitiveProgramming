#include <bits/stdc++.h>

using namespace std;

int dx[] = {+2, +2, -2, -2, +1, +1, -1, -1};
int dy[] = {+1, -1, +1, -1, +2, -2, +2, -2};

char grid[8][8];
int srcx, srcy, tgtx, tgty, vis[8][8];

int sh_dist(int x, int y){
	queue<pair<int, int> > bfs;
	bfs.push(make_pair(x, y));

	vis[x][y] = 1;
	while(!bfs.empty()){
		int curx = bfs.front().first;
		int cury = bfs.front().second;
		bfs.pop();
		for(int i=0;i<8;i++){
			int xn = curx + dx[i];
			int yn = cury + dy[i];
			if(xn >= 0 and yn >= 0 and xn < 8 and yn < 8){
				if(!vis[xn][yn] and grid[xn][yn] != 'X'){
					vis[xn][yn] = vis[curx][cury] + 1;
					bfs.push(make_pair(xn, yn));
				}
			}
		}
	}
	return vis[tgtx][tgty] - 1;
}

int main(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin >> grid[i][j];
			if(grid[i][j] == 'I') srcx = i, srcy = j;
			if(grid[i][j] == 'F') tgtx = i, tgty = j;
		}
	}
	if(sh_dist(srcx, srcy) == -1) cout << "Impossivel ir de I a F" << endl;
	else cout << "Numero minino de movimentos: " << sh_dist(srcx, srcy) << endl;
	return 0;
}
