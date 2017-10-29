#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int num[N];
int parsum[2];
int ans;
vector<char> ord;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
        if(i%2 == 0) parsum[0] += num[i];
        else parsum[1] += num[i];
    }
    for(int i = 0, j = n - 1;i < j;)
    {
        cout << parsum[0] << ' ' << parsum[1] << endl;
        bool a;
        if(parsum[0] > parsum[1]) ans += num[i], parsum[0] -= num[i], i++, ord.push_back('L');
        else ans += num[j], parsum[1] -= num[j], j--, a = 1, ord.push_back('R');

        if(num[i] > num[j]){ parsum[0] -= num[i], i++; if(a) swap(parsum[0], parsum[1]);}
        else{ parsum[1] -= num[j], j--; if(!a) swap(parsum[0], parsum[1]);}
    }
    cout << ans << endl;
    for(auto c : ord) cout << c;
    cout << endl;

}
