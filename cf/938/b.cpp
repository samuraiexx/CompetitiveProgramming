#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
const int N = 1e5 + 5;
int prices[N];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> prices[i];

  int m = 1e6;

  sort(prices, prices + n);
  int a = 1, b = 1e6;
  for(int i = 0; i < n; i++){
    if(prices[i] <= m/2) a = prices[i];
    if(prices[i] > m/2) b = min(b, prices[i]);
  }

  cout << max(a - 1, (m - b)) << endl;
}
