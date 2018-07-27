#include <iostream>

using namespace std;

double xs[5000], ys[5000];

int con[5000];
int qnt[5000];

bool dist2(int i, int j)
{
	return (xs[i] - xs[j])*(xs[i] - xs[j]) + (ys[i] - ys[j])*(ys[i] - ys[j]) <= 1;
}

int father(int x)
{
	if(con[x] = x)
		return x;
	return con[x] = father(con[x]);
}

void conect(int x, int y)
{
	father(x);
	father(y);
	if(con[x] == con[y])
		return;
	if(qnt[con[x]] > qnt[con[y]])
		swap(x, y);
	qnt[con[y]] += qnt[con[x]];
	con[x] = con[y];
	return;
}

int main(){
	int n;
	vector<pair<int, int>> newt;
	while(cin >> n){
		for(int i = 0; i < n; i++)
			cin >> xs[i] >> ys[i], con[i] = i, qnt[i] = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i != j && dist2(i, j))
						 
	}
}
