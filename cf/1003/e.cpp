#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 4e6 + 5;

vector<int> adj[N];

int cnt;
int n, d, k;

void dfs(int p, int ch){
  if(ch == 0) return;
  for(int i = 0; i < k - 1 and cnt <= n; i++){
    int nb = cnt++;
    adj[p].push_back(nb), dfs(nb, ch-1);
  }
}

int main(){
  cin >> n >> d >> k;
  d++;

  if(k == 1 and n > 2 or k == 1 and d > 2 or n < d)
    return cout << "NO" << endl, 0;

  for(int i = 1; i < d; i++)
    adj[i].push_back(i + 1);

  cnt = d + 1;

  for(int i = 2; i < d and cnt <= n; i++){
    for(int j = 0; j < k - 2 and cnt <= n; j++){
      int nb = cnt++;
      adj[i].push_back(nb);
      dfs(nb, min(i - 1, d - i) - 1); 
    }
  }
  //db(cnt _ n);

  if(cnt <= n)
    return cout << "NO" << endl, 0;

  cout << "YES" << endl;
  
  for(int i = 1; i < cnt; i++)
    for(auto x : adj[i])
      cout << i << ' ' << x << endl;
}
