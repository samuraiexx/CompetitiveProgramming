#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    int standing = 0;
    char last = '$';
    for(auto c : s){
        if(c == last) standing++;
        else standing = 1;
        if(standing == 7) break;
        last = c;
    }

    if(standing == 7) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
