#include <bits/stdc++.h> 
using namespace std; 
string n;
string ans;

bool backtrack(vector<int> used, int d, bool equals){
    int i = 9;
    if(equals) i = n[d] - '0';
    for(; i >= 0; i--)
        if(used[i] < 2) {
            used[i]++;
            ans[d] = i + '0';
            if(d == ans.size() - 1) return true;
            else if(backtrack(used, d + 1, ans[d] == n[d] && equals)) return true;
            used[i]--;
        }
    return false;
}

int main(){
    cin >> n;
    ans.resize(n.size());
    backtrack(vector<int>(10), 0, true);
    string ans2;
    bool lz = true;
    for(int i = 0; i < ans.size(); i++)
        if(lz == false or ans[i] != '0') lz = false, ans2.push_back(ans[i]);
    cout << ans2 << endl;
    return 0;
}
