#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
typedef long long ll;
const int N = 3e2;
int ln[N][N];
int m[N][N];
int cnt[N];

int main(){
  int n;
  int x = -1;
  cin >> n;
  for(int i = 0; i < 2*n; i++)
    for(int j = 0; j < n; j++){
      cin >> ln[i][j];
      if(j == 0){
        cnt[ln[i][j]]++;
        if(cnt[ln[i][j]] == 2) x = i;
      }
    }

  for(int i = 0; i < n; i++){
    int y = -1;
    for(int j = 0; j < 2*n; j++)
      if(j != x and ln[x][i] == ln[j][0]) { y = j; break; }

    for(int j = 0; j < n; j++)
      m[i][j] = ln[y][j];
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cout << m[i][j] << ' ';
  cout << endl;
}
