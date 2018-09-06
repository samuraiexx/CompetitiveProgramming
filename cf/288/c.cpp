#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e7;


// Trie <O(|S|), O(|S|)>
int trie[N][2], trien = 1;
int cnt[N];

int add(int u, bool c){
  if (trie[u][c]) return trie[u][c];
  return trie[u][c] = ++trien;
}

void addx(int x){
  int u = 1;
  cnt[u]++;
  for(int i = 22; i >= 0; i--){
    bool c = x&(1 << i);
    u = add(u, c);
    cnt[u]++;
  }
}

int remx(int x){
  int ans = 0;
  int u = 1;
  cnt[u]--;
  for(int i = 22; i >= 0; i--){
    bool c = x&(1 << i);

    if(cnt[trie[u][!c]])
      cnt[trie[u][!c]]--, u = trie[u][!c], ans += (1 << i);
    else cnt[trie[u][c]]--, u = trie[u][c];
  }

  return ans;
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i <= n; i++)
    addx(i);
  
  ll ans = 0;
  vector<int> asd;
  for(int i = 0; i <= n; i++){
    int x = remx(i);
    asd.pb(x^i);
    ans += x;
  }
  
  cout << ans << endl;
  for(auto x : asd)
    cout << x << ' ';
  cout << '\n';
}
