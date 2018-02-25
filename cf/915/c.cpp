#include<bits/stdc++.h>
using namespace std;

vector<int> a, b;

vector<int> dpf(int i, int j, vector<int> c){
    int z = j, a;
    vector<int> ans;
    if(c.empty()) return ans;

    for(a = 0; a < c.size(); a++)
        if(b[i] >= c[a])
            if(z) z--;
            else break;

    if(a == c.size()) return ans;
    ans.push_back(c[a]);
    if(c.size() == 1) return ans;

    vector<int> nx;
    bool f = false;
    for(auto x : c)
        if(!f and x == c[a]) f = true;
        else nx.push_back(x);

    if(c[a] < b[i]){
        for(auto x : nx) ans.push_back(x);
        return ans;
    }


    j = 0;
    for(; j + i < b.size(); j++){
        vector<int> d(dpf(i + 1, j, nx));
        if(d.size() == 0) continue;
        for(auto x : d) ans.push_back(x);
        return ans;
    }
    return vector<int>();
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    for(auto c : s1) a.push_back(c - '0');
    for(auto c : s2) b.push_back(c - '0');

    sort(a.begin(), a.end(), greater<int>());

    if(b.size() > a.size()){
        for(auto x : a) cout << x;
        cout << endl;
        return 0;
    }

    for(int j = 0; j < b.size(); j++){
        vector<int> d(dpf(0, j, a));
        if(d.size() == 0) continue;
        for(auto x : d) cout << x;
        cout << endl;
        break;
    }
}
