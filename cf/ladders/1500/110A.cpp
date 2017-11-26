#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    int ln = 0;
    bool lln = true;
    for(auto c : s)
        if(c == '4' or c == '7') ln++;

    if(ln == 0) lln = false;
    while(ln){
        if(ln%10 != 4 and ln%10 != 7){
            lln = false;
            break;
        }
        ln /= 10;
    }
    
    if(lln) cout << "YES"; else cout << "NO";
    return 0;
}
