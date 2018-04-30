#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 2e5 + 5;
vector<int> ch[N];
bool dest[N];

bool dfs(int n, bool print){
  int amt = 0;
  for(auto c : ch[n])
    amt += dfs(c, print);
  dest[n] = (ch[n].size() - amt)&1;
  
  if(print and dest[n]) cout << n << endl;
  return dest[n];
}

int main(){
  int n, root;
  cin >> n;
  for(int i = 1, a; i <= n; i++){
    cin >> a, ch[a].push_back(i);
    if(a == 0) root = i;
  }

  if(dfs(root, false)) return cout << "NO" << endl, 0;
  cout << "YES" << endl;

  dfs(root, true);
  dest[root] = true, cout << root << endl;

  for(int i = 1; i <= n; i++)
    if(!dest[i]) cout << i << endl;
}
