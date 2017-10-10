#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int count = 0;
    cin >> t;
    for(int i = 0, ans;i <= 4; i++)
    {
        cin >> ans;
        if(ans == t) count++;
    }
    cout << count << endl;
    return 0;
    
}
