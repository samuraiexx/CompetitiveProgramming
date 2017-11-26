#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    long long ans = 0;
    long long s1 = 0, s2 = 0;
    vector<long long> as;
    long long qs = 0;
    cin >> s;

    for(auto c : s){
        if(c == 'Q'){
            qs++;
            for(auto p : as) ans += p;
        }
        if(c == 'A')
            as.push_back(qs);
    }
    cout << ans << endl;
}
