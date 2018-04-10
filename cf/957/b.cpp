#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 100;
char mt[N][N];
set<int> cl[N];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      cin >> mt[i][j];
      if(mt[i][j] == '#') cl[i].insert(j);
    }

  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++){
      if(cl[i] == cl[j]) continue;
      for(auto x : cl[i])
        if(cl[j].count(x)) return cout << "No" << endl, 0;
    }

  cout << "Yes" << endl;
}
