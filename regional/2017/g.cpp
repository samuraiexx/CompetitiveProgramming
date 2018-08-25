#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " << 
typedef long long ll;
const int mod = 1e9 + 5;
const int N = 1e5 + 5;

pair<int, int> ch[N];
pair<ll, ll> w[N];
int st[N];
int cnt[N];

pair<ll, ll> dfs(int n){ // # of ways to return {false, true}
  if(n == 0) return {1, 1};
  auto p1 = dfs(ch[n].st);
  auto p2 = dfs(ch[n].nd);

  w[n] = {(p1.nd*p2.nd)%mod, (p1.st*p2.nd + p1.st*p2.st + p1.nd*p2.st)%mod};

  return w[n];
}

pair<ll, ll> dfs2(int n){  // # of ways it should return {false, true} but doesnt
  if(n == 0) return {0, 0};
  if(st[n] == 0) return {0, w[n].nd};
  if(st[n] == 1) return {w[n].st, 0};

  auto fr1 = dfs2(ch[n].st);
  auto fr2 = dfs2(ch[n].nd);
  auto sh1 = w[ch[n].st];
  auto sh2 = w[ch[n].nd];

  return {fr1.nd*sh2.nd + fr2.nd*sh1.nd - fr1.nd*fr2.nd,
          
         };
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> ch[i].st >> ch[i].nd >> st[i];
    cnt[ch[i].st]++, cnt[ch[i].nd]++;
  }
  int rt;
  for(int i = 0; i < n; i++)
    if(cnt[i] == 0) rt = i;

  dfs(rt);
  auto p = dfs2(rt);
  cout << p.st + p.nd << '\n';
}
