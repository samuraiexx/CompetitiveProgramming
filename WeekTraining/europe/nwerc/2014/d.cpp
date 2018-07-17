#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5*1e5 + 1;

ll nodes[N];
bool s[N];
int ln[N], rn[N];
int inc[N];


int main(){
    int m;
    queue<int> q;
    cin >> nodes[1] >> m;
    for(int i = 1; i <= m; i++)
    {
        char c;
        int l, r;
        cin >> c >> ln[i] >> rn[i];
        if(c == 'R') s[i] = 1;
        inc[ln[i]]++, inc[rn[i]]++;
    }
    for(int i = 1; i < m; i++)
        if(!inc[i]) q.push(i);
    while(q.size())
    {
        int p = q.front(); q.pop();
        nodes[ln[p]] += nodes[p]/2; nodes[rn[p]] += nodes[p]/2;
        if(nodes[p]%2 == 1)
        {
            if(s[p]) nodes[rn[p]]++;
            else nodes[ln[p]]++;
            s[p] = !s[p];
        }
        if(!--inc[rn[p]]) q.push(rn[p]);
        if(!--inc[ln[p]]) q.push(ln[p]);
    }
    for(int i = 1; i <= m; i++)
        if(s[i]) cout << 'R';
        else cout << 'L';

    cout << endl;
    return 0;
}
