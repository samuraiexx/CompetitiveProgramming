#include <bits/stdc++.h>

using namespace std;

map<string, set<string> > m;
string ord[] = {"Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw"};

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	string dum;
	getline(cin, dum);
	while(n--){
		string al, hs;
		getline(cin, al);
		getline(cin, hs);
		m[hs].insert(al);
	}
	for(int i=0;i<4;i++){
		cout << ord[i] << ":" << endl;
		for(set<string>::iterator it = m[ord[i]].begin(); it != m[ord[i]].end(); it++) cout << *it << endl;
		cout << endl;
	}
	return 0;
}
