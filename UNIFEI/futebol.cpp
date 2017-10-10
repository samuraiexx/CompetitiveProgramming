#include <bits/stdc++.h>

using namespace std;

vector<int> yr;
map<string, int> pt;
map<int, set<string> > rank;

int main(){
	int n;
	cin >> n;
	while(n--){
		int y;
		cin >> y;
		yr.push_back(y);
		for(int i=0;i<20;i++){
			string team; int p;
			string s;
			while(cin >> s, s[0] != '-'){
				if(team.size() != 0) team = team + " " + s;
				else team = s;
			}
			cin >> p;
			// cout << team << ' ' << p << endl;
			if(pt[team]) rank[pt[team]].erase(team);
			pt[team] += p;
			rank[pt[team]].insert(team);
		}
	}
	sort(yr.begin(), yr.end());
	cout << "Os 10 melhores do ano de ";
	if(yr.size() > 1){
		for(size_t i=0;i<yr.size()-2;i++) cout << yr[i] << ", ";
		cout << yr[yr.size()-2] << " e " << yr[yr.size()-1] << ":" << endl;
	}
	else cout << yr[0] << ":" << endl;

	int p = 1;
	map<int, set<string> >::reverse_iterator it = rank.rbegin();
	while(p <= 10){
		set<string> s = it->second;
		for(set<string>::iterator jt = s.begin(); jt != s.end(); jt++){
			cout << p++ << " - " << *jt << " - " << pt[*jt] << endl;
			if(p > 10) break;
		}
		it++;
	}
	return 0;
}
