#include <bits/stdc++.h>

using namespace std;
const int N = 50;
const int M = 200;

int g[M][N];
int sum[M];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1;i<=m;i++) for(int j=0;j<=n;j++) scanf("%d", &g[i][j]);

    vector<int> c = {1, 10, 100, 1000, 10000};
    
    for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) sum[i] += g[i][j];    

    int ans = 0;
    for(int i=1;i<=m;i++){
        int bonus = 0;
        for(int p : c) if(sum[i] + p - g[i][1] <= g[i][0]) bonus = p;
        //printf("%d: %d\n", bonus, g[i][1]);
        ans += (bonus - g[i][1] * (sum[i] <= g[i][0]));
    }

    printf("%d\n", ans);
}
