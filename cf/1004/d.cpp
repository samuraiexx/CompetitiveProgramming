#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e6 + 5;
int cnt[N];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int main(){
  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    cnt[a]++;
  }

  cnt[0]--;
  int r = 1, c = 1;

  while(1){
    if(r < c){
      map<int, int> need;
      for(int i = 0; i < c; i++)
        need[r + i]++;

      bool ok = true;
      for(auto p : need)
        if(cnt[p.st] < p.nd) ok = false;
      if(ok){
        for(auto p : need)
          cnt[p.st] -= p.nd;
        r++;
        continue;
      }
    }
    map<int, int> need;
    for(int i = 0; i < r; i++)
      need[c + i]++;

    bool ok = true;
    for(auto p : need)
      if(cnt[p.st] < p.nd) ok = false;
    if(ok){
      for(auto p : need)
        cnt[p.st] -= p.nd;
      c++;
    } else break;
  }

  int dr = 1, dc = 1;

  db(r _ c);
  for(int i = 0; i <= 5; i++)
    db(i _ cnt[i]);
  
  while(1){
    if(r < c){
      map<int, int> need;
      for(int i = 0; i < c; i++)
        need[dr + abs(i - dc + 1)]++;

      bool ok = true;
      for(auto p : need){
        if(cnt[p.st] < p.nd) ok = false;
      }

      if(ok){
        for(auto p : need)
          cnt[p.st] -= p.nd;
        r++;
        dr++;
        continue;
      }
    }
    map<int, int> need;
    for(int i = 0; i < r; i++)
      need[dc + abs(i - dr + 1)]++;

    bool ok = true;
    for(auto p : need)
      if(cnt[p.st] < p.nd) ok = false;
    if(ok){
      for(auto p : need)
        cnt[p.st] -= p.nd;
      c++;
      dc++;
    } else break;
  }

  cout << r << ' ' << c << endl;
  cout << dr << ' ' << dc << endl;

}
