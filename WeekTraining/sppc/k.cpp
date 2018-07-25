#include <bits/stdc++.h>

using namespace std;

int cntkiwi[26], cntkang[26];

bool isUpper(char c) { return c <= 'Z' and c >= 'A' ; }

char toUpper(char c) { return isUpper(c) ? c : c + 'A' - 'a'; } 

string kiwi = "KIWIBIRD", kangaroo = "KANGAROO";
string key;

int main(){
    for(char c : kiwi) cntkiwi[toUpper(c) - 'A']++; 
    for(char c : kangaroo) cntkang[toUpper(c) - 'A']++; 

    cin >> key;
    int sumkiwi = 0, sumkang = 0;
    for(char c : key) {
        sumkiwi += cntkiwi[toUpper(c) - 'A'];
        sumkang += cntkang[toUpper(c) - 'A'];
    } 

    if(sumkiwi == sumkang) cout << "Feud continues" << endl;
    else cout << ((sumkiwi > sumkang) ? "Kiwis" : "Kangaroos") << endl;

    return 0;
}
