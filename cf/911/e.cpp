#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    int nxt = 1;
    vector<int> ans;
    stack<int> s;

    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        ans.push_back(x);
        if(s.size() and x > s.top()) return cout << -1 << endl, 0;
        if(nxt == x) nxt++;
        else s.push(x);

        while(s.size() and s.top() == nxt) s.pop(), nxt++;
    }

    while(nxt <= n){
        if(s.empty()){
            for(int i = n; i >= nxt; i--) ans.push_back(i);
            break;
        }

        int t;
        t = s.top(), s.pop();
        for(int i = t - 1; i >= nxt; i--) ans.push_back(i);
        nxt = t+1;
    }
    
    for(auto x : ans)
        cout << x << ' ';
    cout << endl;
    return 0;
}
