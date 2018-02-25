#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int one = 0, two = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 1) one++;
        else two++;
    }

    int ans = min(one, two);
    ans += (one - ans)/3;
    cout << ans << endl;
}
