#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int val[N];

int main(){
  int n, a;

  while(cin >> n >> a, n or a){
    int s = 0;
    memset(val, 0, sizeof val);

    for(int i = 0, x; i < n; i++)
      cin >> x, val[x - 1]++;
    for(int i = N - 2; i >= 0; i--) val[i] += val[i + 1];

    int i;
    for(i = N - 2; i >= 0; i--) 
      if(s + val[i] <= a) s += val[i];
      else break;

    if(i < 0)
      if(s < a) { cout << "-.-" << endl; continue; }
      else { cout << ":D" << endl; continue; }

    double ans = i + (a != s ? 1 - (a - s)/(double)val[i] : 1);

    printf("%.4lf\n", ans);
  }
}
