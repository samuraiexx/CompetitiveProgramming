#include<bits/stdc++.h>
using namespace std;

pair<char, char> io[1000];
int cap[1001];
bool desc[1000];
int n;

bool lf(int i, int j){
    if(j >= n) return 0;
    bool d = 0;
    if(io[i].second == io[j].first) d = 1;
    bool fd = 0;
    if(cap[i] > cap[j]) fd = lf(i, j + 1);
    desc[j] = desc[j] or fd;
    return d or fd;
}

int main(){
    while(cin >> n, n){
        for(int i = 0; i < n; i++){
            char in, out;
            cin >> cap[i] >> in >> out;
            io[i] = {in, out};
        }
        for(int i = 0; i < n; i++)
            lf(i, i + 1);

        int ans = 0;
        for(int i = 0; i < n; i++) ans += !desc[i];
        cout << ans << endl;
        
    }
}

