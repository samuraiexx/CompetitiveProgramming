#include<bits/stdc++.h>
using namespace std;

int find(int n){
    for(int i=0;i<=n;i++) if(i*(i+1)/2 == n) return i;
    return -1;
}

int main(){
    int d, r, t;
    scanf("%d %d %d", &d, &r, &t);
    for(int i=0;i<=r;i++){
        if((find(r-i+6) != -1) and (find(t+i+3) != -1)){
            if(find(t+i+3) < 3 and find(r-i+6) - find(t+i+3) < d) return printf("0\n"), 0;
            else if(find(r-i+6) - find(t+i+3) == d) return printf("%d\n", i), 0;
        }
    }
    return 0;
}
