#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
bool mt[15][15];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){
  char c;
  int ext = 0;
  int m = 0, n = 0;
  for(int i = 1; ext != EOF; i++)
    for(int j = 1; ; j++, m = max(m, j)){
      ext = scanf("%c", &c);
      if(c == '\n') break;
      mt[i][j] = c - '0';
    }
  n = m;

  bool ok = 0;
  while(!ok){
    ok = 1;
    for(int i = 1; i < n; i++)
      for(int j = 1; j < m; j++)
        if(!mt[i][j]){
          int cnt = 0;
          for(int k = 0; k < 4; k++)
            if(mt[i + dx[k]][j + dy[k]]) cnt++;
          if(cnt >= 2) mt[i][j] = true, ok = 0;
        }
  }

  for(int i = 1; i < n; i++){
    for(int j = 1; j < m; j++)
      cout << mt[i][j];
    cout << endl;
  }
}
