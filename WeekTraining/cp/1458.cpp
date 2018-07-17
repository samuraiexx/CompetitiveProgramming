#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

double distdp[12][12];
double dp[12][12][1000];

char buffer [1000];

double deltat(char a, char b)
{
	int i = a - '1', j = b - '1';
	if(i == j)
		return 0;
	if(i > j)
		swap(i, j);
	if(distdp[i][j])
		return distdp[i][j];
	int x1 = i%3, x2 = j%3;
	int y1 = i/3, y2 = j/3;
	return distdp[i][j] = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))/30;
}

double dpr(char i, char j, int pos)
{
	if(i > j)
		swap(i, j);
	if(buffer[pos] == '\n')
		return 0;
	if(dp[i - '1'][j - '1'][pos])
		return dp[i - '1'][j - '1'][pos];
	return dp[i - '1'][j - '1'][pos] =  min(dpr(buffer[pos], j, pos + 1) + deltat(i, buffer[pos]),
						dpr(i, buffer[pos], pos + 1) + deltat(j, buffer[pos])) + 0.2;
}

int main()
{
	map<char, string> tec;
	string in;
	char c;
		tec['a'] = "2", tec['b'] = "22", tec['c'] = "222", tec['d'] = "3",
		tec['e'] = "33", tec['f'] =  "333", tec['g'] = "4", tec['h'] = "44",
		tec['i'] = "444", tec['j'] = "5", tec['k'] = "55", tec['l'] = "555",
		tec['m'] = "6", tec['n'] = "66", tec['o'] = "666", tec['p'] = "7",
		tec['q'] = "77", tec['r'] = "777", tec['s'] = "7777", tec['t'] = "8",
		tec['u'] = "88", tec['v'] = "888", tec['w'] = "9", tec['x'] = "99",
		tec['y'] = "999", tec['z'] = "9999", tec[' '] = '9' + 2;
	while(!getline(cin, in).eof())
	{
		for(int i = 0; i < 12; i++)
			for(int j = 0; j < 12; j++)
				for(int k = 0; k < 1000; k++)
					dp[i][j][k] = 0;
		int i = 0;
		int flag;
		for(auto c : in)
		{
			if(i > 0 && buffer[i - 1] == *tec[c].begin())
				buffer[i++] = ('9' + 3); 
			for(auto b : tec[c])
				buffer[i++] = b;
		}
		buffer[i] = '\n';
		printf("%.2lf\n", dpr('4', '6', 0));
	}
	return 0;
}
