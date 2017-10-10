#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second

string num[70000];
string sub[70000][9][9];
pair<int, int> mn[70000];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    map<string, int> isub;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> num[i], mn[i] = {0, 8};
    for(int i = 0; i < n; i++)
    {
        set<string> tisub;
        for(int j = 0; j < 9; j++)
            for(int k = j; k < 9; k++)
            {
                if(j == k) sub[i][k][k] = num[i][k];
                else sub[i][j][k] = sub[i][j][k - 1] + num[i][k];
                if(!tisub.count(sub[i][j][k]))
                {
                    isub[sub[i][j][k]]++;
                    tisub.insert(sub[i][j][k]);
                }
            }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 9; j++)
            for(int k = j; k < 9; k++)
            {
                if(isub[sub[i][j][k]] == 1)
                    if(k - j < mn[i].nd - mn[i].st)
                        mn[i].st = j, mn[i].nd = k;
            }
    for(int i = 0; i < n; i++)
        cout << sub[i][mn[i].st][mn[i].nd] << '\n';
    return 0;
}
