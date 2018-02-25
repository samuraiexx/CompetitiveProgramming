#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> el;
    vector<int> inc;
    int cnt = 0;
    string s;
    cin >> s;
    int n = s.size();

    for(int i = 0; i < n; i++) el.insert(i);
    for(int i = 0; i < n - 1; i++)
        if(s[i] != s[i + 1]) inc.push_back(i);

    while(inc.size()){
        vector<int> inc2;
        set<int> del;
        auto it = el.begin();
        for(auto x : inc)
            if((it = next(el.find(x))) != el.end() and s[*it] != s[x])
                del.insert(x), del.insert(*it);
        if(del.size()) cnt++;
        for(auto x : inc) if(*el.begin() != x){
            int y = *prev(el.find(x));
            if(!del.count(y)) inc2.push_back(y);
        }
        for(auto x : del) el.erase(x);
        inc.clear();
        for(auto x : inc2) inc.push_back(x);
    }
    cout << cnt << endl;
    return 0;
}
