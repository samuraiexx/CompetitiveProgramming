#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int tr[N];
int ex[N];

int main(){
    int n, d;
    int ans = 0;
    scanf("%d%d", &n, &d);
    
    for(int i = 1; i <= n; i++){
        scanf("%d", &tr[i]);
    }

    int money = 0;
    for(int i = 1;i <= n; i++){
        money += tr[i];
        if(money < 0 and tr[i] == 0) ex[i] = -money, money = 0;
        if(money > d) return cout << -1 << endl, 0;
    }

    for(int i = n; i > 1; i--){
        money -= tr[i];
        if(money - tr[i - 1] > d) money -= ex[i];
        else ex[i - 1] += ex[i], ex[i] = 0;
    }

    for(int i = 1; i <= n; i++) if(ex[i]) ans++;

    cout << ans << endl;
    return 0;
}
