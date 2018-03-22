#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e7 + 5;

// Trie <O(|S|), O(|S|)>
int trie[N][2], trien = 1;
int cnt[N][2];
int key[N];

int add(int u, bool c){
  cnt[u][c]++;
  if (trie[u][c]) return trie[u][c];
  return trie[u][c] = ++trien;
}

int get_max(int u, int i, int y){
  if(i < 0) return 0;
  bool b = (1 << i)&y;
  int x;

  if(cnt[u][b]){
    cnt[u][b]--;
    x = get_max(trie[u][b], i - 1, y);
  }else{
    cnt[u][!b]--;
    x = get_max(trie[u][!b], i - 1, y);
    x += (1 << i);
  }
  return x;
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> key[i];
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    int u = 1;
    for(int i = 30; i >= 0; i--)
      if((1 << i) & x) u = add(u, 1);
      else u = add(u, 0);
  }

  for(int i = 0; i < n; i++){
    cout << get_max(1, 30, key[i]) << ' ';
  }
  cout << endl;
}
