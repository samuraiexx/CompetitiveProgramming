#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500 + 5;
const int INF = 0x3f3f3f3f;

int dist[N][N];
bool in[N];

int q[N];
long long ans[N];

int main(){
  int n;
  cin >> n;

  memset(dist, 0x3f, sizeof dist);

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      cin >> dist[i][j];

  for(int i = 1; i <= n; i++)
    cin >> q[i];

  for(int i = n; i > 0; i--){
    int x = q[i];
    in[x] = true;
    ll ansi = 0;

    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++){
        dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][j]);

        if(in[i] and in[j])
          ansi += dist[i][j];
      }
    ans[i] = ansi;
  }

  for(int i = 1; i <= n; i++)
    cout << ans[i] << " \n"[i == n];
}
