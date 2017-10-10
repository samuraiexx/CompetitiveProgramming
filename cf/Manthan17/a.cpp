#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    set<string> present;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(present.count(s))
            cout << "YES\n";
        else
            cout << "NO\n";
        present.insert(s);
    }
    return 0;
}
