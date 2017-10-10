#include<bits/stdc++.h>
using namespace std;

int dp[3000][3000];
pair<char, int> dpa[3000];
string s;

bool iscon(char c) {
    if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') return false;
    return true;
}

int dpf(int i, int j)
{
    if(dp[i][j]) return dp[i][j];
    int spaces = j - i + 1;
    for(int k = i; k < j; k++)
    {
        dpf(i, k), dpf(k, j);
        
        if(iscon(s[k]))
        {
            if(cd.second == '$') cb.first++;
            else if(cd.second != s[k]) c.first++, cb.second = '$';
            else if(cd.second == '#') c.first++, cb.second = s[k];
            else cb.first++;
        }
        else cb = {0, '#'};
        if(cb.first >= 3 && cb.second == '$')
            dp[i][j] = 1;
    }
    for(int k = i; k < j; k++)
    {
        dp[i][j] = 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> s;
    in_a_row[0] = iscon(s[o]) ? {s[0], 1} : {'@', 0};

}
