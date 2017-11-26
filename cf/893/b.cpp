#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> div;
    set<int> gd;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) if(n%i == 0) div.push_back(i);
    for(int k = 1, a = 0; a <= n; k++)
        gd.insert(a = (((1 << k) - 1)*(1 << k - 1)));
    for(int i = div.size() - 1; i >= 0; i--)
        if(gd.count(div[i])) return printf("%d\n", div[i]), 0;
    return 0;
}
