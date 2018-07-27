#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    map<int, int> lis;
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(lis.empty() or lis.begin()->first > b) { lis[b] = b - a + 1; continue; }
        auto p = lis.lower_bound(b);
        p--;
        lis[b] = p->second + b - a + 1; 
        auto tmp = ++p;
        while(++tmp, tmp != lis.end() && tmp->second <= lis[b]) lis.erase(tmp), tmp = p;
    }
    auto p = --lis.end();
    printf("%d\n", p->second);
    return 0;
}
