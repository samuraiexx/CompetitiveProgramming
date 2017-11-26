#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, p1 = 1, p2 = 2, exp = 3;
    scanf("%d", &n);
    for(int i = 0, a; i < n; i++){
        scanf("%d", &a);
        if(a == p1) swap(p2, exp);
        else if(a == p2) swap(p1, exp);
        else return printf("NO\n"), 0;
    }
    return printf("YES\n"), 0;
}
