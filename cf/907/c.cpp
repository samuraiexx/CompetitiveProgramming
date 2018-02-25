#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt = 0;
    set<char> pos;
    for(char i = 'a'; i <= 'z'; i++) pos.insert(i);
    cin >> n;
    for(int i = 0; i < n;i++){
        char o;
        cin >> o;

        if(o == '.'){
           string w;
           cin >> w;
           for(char a : w) pos.erase(a);
        }
        else if(o == '!'){
            if(pos.size() == 1) cnt++;
            set<char> x;
            string w;
            cin >> w;
            for(char a : w) x.insert(a);
            for(char i = 'a'; i <= 'z'; i++) if(!x.count(i)) pos.erase(i);
        }
        else {
            if(pos.size() == 1 and i != n - 1) cnt++;
            char c;
            cin >> c;
            pos.erase(c);
        }
    }
    cout << cnt << endl;
}

