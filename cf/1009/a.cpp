#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int n, m;
  cin >> n >> m;

  queue<int> q1, q2;

  for(int i = 0, a; i < n; i++)
    cin >> a, q1.push(a);;

  for(int i = 0, a; i < m; i++)
    cin >> a, q2.push(a);;

  q2.push(-1);
  
  int ans = 0;

  while(q2.front() > 0 and q1.size()){
    if(q2.front() >= q1.front()) ans++, q2.pop();
    q1.pop();
  }

  cout << ans << endl;
}
