#include <bits/stdc++.h>

using namespace std;
const int N = 3e3+5;

map<int, set<int> > ans;
int res[N];
pair<int, int> in[N];

int main(){
	int p=0;
	while(1){
		string reg; int qnum, per;
		cin >> reg;
		if(reg == "#") break;
		cin >> qnum >> per;
		in[p++] = make_pair(qnum, per);
	}
	int k, ma = 0x3f3f3f3f, last = in[0].first;
	cin >> k;
	for(int j=1;j<=k;j++) ans[j*in[0].second].insert(in[0].first), ma = j*in[0].second;
	for(int i=1;i<p;i++){
		for(int j=1;j<=k;j++){
			if(j*in[i].second < ma){
				ans[j*in[i].second].insert(in[i].first);
				ans[ma].erase(ans[ma].find(last));
				if(ans[ma].empty()) ans.erase(ma);
			}
			else if(j*in[i].second == ma and in[i].first < last){
				ans[j*in[i].second].insert(in[i].first);
				ans[ma].erase(ans[ma].find(last));
				if(ans[ma].empty()) ans.erase(ma);
			}
			map<int, set<int> >::reverse_iterator it = ans.rbegin();
			ma = it->first;
			set<int>::reverse_iterator jt = (it->second).rbegin();
			last = *jt;
		}
	}
	for(map<int, set<int> >::iterator it = ans.begin(); it != ans.end(); it++){
		set<int> s = it->second;
		for(set<int>::iterator jt = s.begin(); jt != s.end(); jt++){
			res[*jt]++;
		}
	}
	for(int i=0;i<N;i++) if(res[i]) cout << "Register " << i << " = " << res[i] << endl;
	return 0;
}
