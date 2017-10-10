#include<bits/stdc++.h>
using namespace std;

int slices[50];
int dp[50]; 
bool dpc[50];
int n, sum;

int dpf(int i)
{
    if(i >= n) return 0;
    if(dp[i]) return dp[i];
    if(i == n - 1){ dpc[i] = true; return dp[i] = slices[i]; }
    int op1 = slices[i], op2 = 0; //op1 give to me, op2 give to her
    for(int j = i + 1; j < n; j++)
    {
        if(dpf(j) && dpc[j]){
             op1 += dpf(j + 1);
              break; 
        }
        else op1 += slices[j];
    }
    op2 = dpf(i + 1);
    dpc[i] = op1 > op2;
    return dp[i] = max(op1, op2);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> slices[i], sum += slices[i];
    dpf(0);
    cout << sum - dp[0] << ' ' << dp[0] << endl;
    return 0;
}
