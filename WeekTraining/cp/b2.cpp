#include <iostream>

using namespace std;

const int INF = 100000000;

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n, m;
		int fw[500][500];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				fw[i][j] = INF;
		cin >> n >> m;
		for(int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			fw[x][y] = fw[y][x] = 1;
		}
		for(int i = 0; i < n; i++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{

				}
			}
		}
	}
	return 0;
}
