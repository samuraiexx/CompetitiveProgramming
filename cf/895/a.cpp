#include<bits/stdc++.h>
using namespace std;
const int N = 361;
int piece[N];
int n;

int main(){
    int ans = 0, st = 0, acm = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> piece[i];

    for(int i = 0; i < 2*n; i++){
        acm += piece[i%n];
        while(acm > 180) acm -= piece[st], st = (st+1)%n;
        ans = max(ans, acm);
    }

    cout << 2*(180 - ans) << endl;
    return 0;
}
