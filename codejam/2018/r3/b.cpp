#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 205;

int probx[N][N];
int sz[N];

int main(){
  int T;
  cin >> T;

  for(int t = 1; t <= T; t++){
    int n;
    cin >> n;

    set<int> used;
    for(int i = 0; i < n; i++){
      int amt;
      cin >> amt;
      double mn = 2;
      int k = -1;

      for(int j = 0; j < amt; j++){
        int x;
        cin >> x;
        probx[i][x]++;
        sz[i]++;
        if(used.count(x)) continue;
        double mx = 0;
        
        int cnt = 0;
        for(int k = i + 1; k < n; k++){
          if(sz[k]) mx += probx[k][x]/(double)sz[k];
          cnt ++;
        }
        if(cnt) mx /= cnt;
        if(mx < mn) 
          k = x, mn = mx;
      }

      if(k != -1) used.insert(k);
      cout << k << endl;
    }
  }
}
