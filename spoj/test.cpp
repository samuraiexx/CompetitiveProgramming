#include <bits/stdc++.h>
using namespace std;
char s1[500], s2[500];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%s", s1, s2);
        printf("%s %s\n", s1, s2);
    }
    return 0;
}
