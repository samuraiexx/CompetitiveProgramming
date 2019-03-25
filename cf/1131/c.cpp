#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;
const int INF = 1e9 + 1;
int v[N];

int get(int i, int j){
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i];
  sort(v, v + n);

  deque<int> dq;
  for(int i = 0; i < n; i++){
    if(dq.empty()) dq.push_back(v[i]);
    else if(i&1) dq.push_front(v[i]);
    else dq.push_back(v[i]);
  }
  for(auto x : dq)
    cout << x << ' ';
  cout << endl;
}
