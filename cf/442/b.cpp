#include<bits/stdc++.h>
using namespace std;

const int N = 5000;

int dp[5000][3];

int main(){
    string in;
    cin >> in;

    if(in[0] == 'a') dp[0][0] = dp[0][2] = 1;
    else dp[0][1] = 1;
    for(int i = 1; i < in.size(); i++)
    {
        if(in[i] == 'a'){
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]) + 1;
        }else{
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i-1][0], dp[i - 1][1]) + 1;
            dp[i][2] = dp[i-1][2];
        }
    }
    cout << max(max(dp[in.size() - 1][0], dp[in.size() - 1][1]), dp[in.size() - 1][2]);
    cout << endl;
    return 0;
}
