#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r_p[4][4] = {	{1, 0, 0, 2},
		{0, 1, 1, 3},
		{2, 2, 3, 0},
		{3, 1, 2, 3}};

void seq(vector<pair<int, pair<double, double>>> &pos, int rot, double s)
{
	cout << pos.size() << endl;
	if(pos.size() == 0 || pos.size() == 1)
		return;
	s /= 2;
	vector<pair<int, pair<double, double>>> ld, lu, rd, ru;
	sort(pos.begin(), pos.end(), [](pair<int, pair<double, double>> p1, pair<int, pair<double, double>> p2) { return p1.second.first < p2.second.first;});
	for(auto a : pos)
		if(a.second.first < s)
			ld.push_back(a);
		else
			rd.push_back(a);
	sort(ld.begin(), ld.end(), [](pair<int, pair<double, double>> p1, pair<int, pair<double, double>> p2) { return p1.second.second < p2.second.second;});
	sort(rd.begin(), rd.end(), [](pair<int, pair<double, double>> p1, pair<int, pair<double, double>> p2) { return p1.second.second < p2.second.second;});
	auto tmp = ld.end();
	for(auto it = ld.begin(); it != ld.end(); it++)
		if(it->second.second > s)
			lu.push_back(make_pair(it->first, make_pair(it->second.first, it->second.second - s)));
		else
			tmp = it;
	lu.erase(tmp, lu.end());
	tmp = rd.end();
	for(auto it = rd.begin(); it != rd.end(); it++)
		if(it->second.second > s)
			ru.push_back(make_pair(it->first, make_pair(it->second.first - s, it->second.second - s)));
		else
			tmp = it, it->second.first -= s;
	rd.erase(tmp, rd.end());

	seq(rd, r_p[rot][3], s), seq(ru, r_p[rot][2], s), seq(ld, r_p[rot][0], s), seq(lu, r_p[rot][1], s);
	pos.clear();
	if(rot == 0)
		pos.insert(pos.end(), ld.begin(), ld.end()), pos.insert(pos.end(), lu.begin(), lu.end()), pos.insert(pos.end(), ru.begin(), ru.end()), pos.insert(pos.end(), rd.begin(), rd.end());
	else if(rot == 1)
		pos.insert(pos.end(), ld.begin(), ld.end()), pos.insert(pos.end(), rd.begin(), rd.end()), pos.insert(pos.end(), ru.begin(), ru.end()), pos.insert(pos.end(), lu.begin(), lu.end());
	else if(rot == 2)
		pos.insert(pos.end(), ru.begin(), ru.end()), pos.insert(pos.end(), lu.begin(), lu.end()), pos.insert(pos.end(), ld.begin(), ld.end()), pos.insert(pos.end(), rd.begin(), rd.end());
	else if(rot == 3)
		pos.insert(pos.end(), ru.begin(), ru.end()), pos.insert(pos.end(), rd.begin(), rd.end()), pos.insert(pos.end(), ld.begin(), ld.end()), pos.insert(pos.end(), lu.begin(), lu.end());
}

int main()
{
	int n;
	double s;
	while(cin >> n >> s)
	{
		map<int, string> xys;
		vector<pair<int, pair<double, double>>> tosort;
		for(int i = 0; i < n; i++)
		{
			double x, y;
			string name;
			cin >> x >> y >> name;
			xys[i] =  name;
			tosort.push_back(make_pair(i, make_pair(x, y)));
		}
		seq(tosort, 0, s);
		for(int i = 0; i < n; i++)
			cout << xys[tosort[i].first] << '\n';

	}
}
