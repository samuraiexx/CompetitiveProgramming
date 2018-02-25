#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    string ans;
    ans.push_back(a[0]);
    for(int i = 1;a[i] < b[0] and i < a.size(); i++)
        ans.push_back(a[i]);
    ans.push_back(b[0]);
    cout << ans << endl;
}
