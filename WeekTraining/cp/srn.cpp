#include <iostream>
#include <string>

using namespace std;

int n;
bool round[200001];
int bit[200001];

void update(int p, bool r)
{
	int pos = p;
	if(r && !round[p])
		for(;p <= n; p += p&-p)
			bit[p]++;
	else if (!r && round[p])
		for(;p <= n; p += p&-p)
			bit[p]--;
	round[pos] = r;		
}

int query(int l, int r)
{
	int som = 0;
	l--;
	for(;r > 0; r-=r&-r)
		som+=bit[r];
	for(;l > 0; l-=l&-l)
		som-=bit[l];
	return som;
}



int main(){
	int q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		update(i, s[0] == s[s.size()-1]);
	}
	for(int i = 0; i < q; i++)
	{
		int opt;
		cin >> opt;
		if(opt == 1)
		{
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << endl;
		}
		else
		{
			int p;
			string s;
			cin >> p >> s;
			update(p, s[0] == s[s.size()-1]);
		}		
	}
	return 0;
}
