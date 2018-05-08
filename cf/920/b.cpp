#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e3 + 5;
int l[N], r[N], s[N];

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) 
      cin >> l[i] >> r[i], s[i] = 0;

    int t = 1;
    int i = 0, j = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) 
      q.push({l[i], i});

    while(q.size()){
      while(q.size() and r[q.front().nd] < t) q.pop();
      if(!q.size()) break;

      t = max(t, q.front().st);
      s[q.front().nd] = t;
      q.pop();
      t++;
    }

    for(int i = 0; i < n; i++) cout << s[i] << ' ';
    cout << endl;
  }
}
