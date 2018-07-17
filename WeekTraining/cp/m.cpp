#include <iostream>
#include <map>
#include <queue>

using namespace std;

char fl[12][12];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class state{
public:
	int xi[4];
	int yi[4];
	state(){
		for(int i = 0; i < 4; i++)
			xi[i] = yi[i] = 0;
	}
};

bool operator <(const state &a, const state &b)
{
	for(int i = 0; i < 4; i++)
		if(a.xi[i] < b.xi[i])
			return true;
		else if(a.xi[i] > b.xi[i])
			return false;
	for(int i = 0; i < 4; i++)
		if(a.yi[i] < b.yi[i])
			return true;
		else if(a.yi[i] > b.yi[i])
			return false;
	return false;
}

int main(){
	int n, w, h, l;
	for(int i = 0; i < 11; i++)
		fl[i][0] = fl[0][i] = 'W';
	while(!(cin >> n >> w >> h >> l).eof())
	{
		state beg;
		map<state, int> dist;
		for(int i = 0; i < 11; i++)
			fl[h + 1][i] = fl[i][w + 1] = 'W';
		for(int i = 1; i <= h; i++)
			for(int j = 1; j <= w; j++)
			{
				char x;
				cin >> x;
				if(x == '.' or x == 'W' or x == 'X') fl[i][j] = x;
				else 
				{
					fl[i][j] = '.';
					beg.xi[x - '1'] = i; 
					beg.yi[x - '1'] = j; 
				}
			}
		queue<pair<int, state>> q;
		dist[beg] = 0x3f3f3f;
		q.push(make_pair(0, beg));
		while(!q.empty()){
			pair<int, state> p = q.front();
			q.pop();
			if(dist.count(p.second) && p.first >= dist[p.second])
				continue;
			if(fl[p.second.xi[0]][p.second.yi[0]] == 'X')
			{
				cout << p.first << '\n';
				break;
			}
			else if(p.first > l)
			{
				cout << "NO SOLUTION\n";
				break;
			}
			dist[p.second] = p.first;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < 4; j++)
				{
					state tmp = p.second;
					int x, y;
					while(fl[x = tmp.xi[i] + dx[j]][y = tmp.yi[i] + dy[j]] != 'W')
					{
						bool ok = 1;
						for(int k = 0; k < 4; k++)
							if(x == tmp.xi[k] && y == tmp.yi[k])
								ok = 0;
						if(!ok)
							break;
						tmp.xi[i] += dx[j], tmp.yi[i] += dy[j];
					}
					if(!dist.count(tmp))
						q.push(make_pair(p.first + 1, tmp));
				}
		}
		if(q.empty())
			cout << "NO SOLUTION\n";


	}
	return 0;
}
