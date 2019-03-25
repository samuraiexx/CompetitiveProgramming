#include<bits/stdc++.h>
using namespace std;

char open[] = { '(', '{', '[' };
char close[] = { ')', '}', ']' };

int main(){
    map<char, int> pos; 
    for(int i = 0; i < 3; i++)
        pos[open[i]] = i, pos[close[i]] = i;

    deque<char> dq;
    stack<char> sk;
    string s;
    cin >> s;
    for(auto c : s) dq.push_back(c);

    for(int i = 0; i < s.size(); i++){
        if(open[pos[s[i]]] == s[i]) sk.push(s[i]);
        else if(sk.size())
            if(pos[s[i]] == pos[sk.top()]) sk.pop();
            else return cout << "NIE" << endl, 0;
    }
    while(sk.size())
        dq.push_back(close[pos[sk.top()]]), sk.pop();

    for(int i = s.size() - 1; i >= 0; i--){
        if(close[pos[s[i]]] == s[i]) sk.push(s[i]);
        else if(sk.size())
            if(pos[s[i]] == pos[sk.top()]) sk.pop();
            else return cout << "NIE" << endl, 0;
    }
    while(sk.size())
        dq.push_front(open[pos[sk.top()]]), sk.pop();

    for(auto c : dq) cout << c;
    cout << endl;
}
