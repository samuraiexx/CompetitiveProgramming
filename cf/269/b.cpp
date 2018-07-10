#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int v[N];
int lis[N];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    double p;
    cin >> v[i] >> p;
  }

  int j = 0;
  for(int i = 0; i < n; i++){
    int p = upper_bound(lis, lis + j, v[i]) - lis;
    if(p == j) j++;
    lis[p] = v[i];
  }

  cout << n - j << endl;
}
