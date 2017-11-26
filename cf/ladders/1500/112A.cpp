#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;
int v[N];

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    for(auto &c : s1)
        if(c >= 'A' and c <= 'Z') c = c - 'A' + 'a';
    for(auto &c : s2)
        if(c >= 'A' and c <= 'Z') c = c - 'A' + 'a';

    int ans = strcmp(s1.c_str(), s2.c_str());
    if(ans == 0) cout << 0 << endl;
    else if(ans < 0) cout << -1 << endl;
    else cout << 1 << endl;
    
    return 0;
}
