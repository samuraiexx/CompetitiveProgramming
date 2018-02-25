#include<bits/stdc++.h>
using namespace std;

bool has(int x){
    if(x%10 == 7 or x/10 == 7) return true;
    return false;
}

int main(){
    int x;
    int h, m;
    cin >> x >> h >> m;
    int time = h*60 + m;
    for(int i = 0; ; i++){
        if(has(time%60) or has(time/60)) return cout << i << endl, 0;
        time = (time - x + 24*60)%(24*60);
    }
    return 0;
}
