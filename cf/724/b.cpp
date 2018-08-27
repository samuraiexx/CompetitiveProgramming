#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 25;
int n, m;

vector<int> v[N];

bool check(){
  for(int i = 0; i < n; i++){
    int cnt = 0;
    for(int j = 0; j < m; j++)
      if(v[j][i] != j + 1) cnt++;

    if(cnt > 2) return false;
  }

  return true;
}

int main(){
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int x;
      cin >> x;

      v[j].push_back(x);
    }
  }

  if(check()) return cout << "YES" << endl, 0;
  for(int i = 0; i < m; i++){
    for(int j = i + 1; j < m; j++){
      swap(v[i], v[j]);
      if(check()) return cout << "YES" << endl, 0;
      swap(v[i], v[j]);
    }
  }

  cout << "NO" << endl;
}
