#include<bits/stdc++.h>
using namespace std;
const int N = 8;
#define st first
#define nd second
typedef long double Ld;
vector<pair<int, double>> part[N];

int chances[N][N];
int main(){
    int p;
    Ld ans = 0;
    cin >> p;
    int n = 1 << p;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> chances[i][j];
    for(int i = 1; i <= n; i++)
        part[0].push_back({i, 1});

    for(int i = 0; i < p; i++)
        for(int j = 0; j < part[i].size(); j += 2)
        {
            int w;
            int c;
            double acm;
            if((c = chances[part[i][j].st][part[i][j + 1].st]) > 50) w = part[i][j].st, acm = part[i][j].nd;
            else w = part[i][j + 1].st, acm = part[i][j + 1].nd;
            acm = acm*max(c, 100 - c)/(Ld)100;
            part[i + 1].push_back({w, acm});
            ans += (1 << i)*acm;
        }
    printf("%.9Lf\n", ans);
    return 0;
}
