#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+5;

set<int> ans1, ans2;
int n, t[N], vis[N][5];

void dfs(int i, int pos, int qt1, int qt2) {
    if(vis[i][pos]) return;

    vis[i][pos] = 1;
    if(i == n){
        if(pos == 2) ans1.insert(qt1+1), ans2.insert(qt2);
        else if(pos == 3) ans1.insert(qt1), ans2.insert(qt2+1);
        return;
    }

    if(pos == 1) {
        if(t[i+1] - t[i] >= 2000) return;
        else dfs(i+1, 2, qt1, qt2);
    }
    else if(pos == 2) {
        if(t[i+1] - t[i] <= 1000) dfs(i+1, 3, qt1, qt2);
        else if(t[i+1] - t[i] >= 2000) dfs(i+1, 1, qt1+1, qt2);
        else dfs(i+1, 3, qt1, qt2), dfs(i+1, 1, qt1+1, qt2);
    }
    else {
        if(t[i+1] - t[i] <= 1000) return;
        else dfs(i+1, 1, qt1, qt2+1);
    }
}

int main(){
   scanf("%d", &n);
   
   for(int i=1; i<=n; i++) scanf("%d", &t[i]);
   
   dfs(1, 1, 0, 0); 

   if(ans1.empty()) printf("Impossible\n");
   else if(ans1.size() > 1 or ans2.size() > 1) { 
       printf("Ambiguous\n");
   }
   else {
       printf("Cars without trailers: %d\nCars with trailers: %d\n", *ans1.begin(), *ans2.begin());
   }
   return 0;
}
