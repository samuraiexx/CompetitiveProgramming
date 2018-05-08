#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5;
bool t[N];

int main(){
  int n, s;
  cin >> n >> s;

  for(int i = 0; i < n; i++){
    int h, m;
    cin >> h >> m;
    t[60*h + m] = true;
  }

  int cnt = s;
  for(int i = 0; i < N; i++){
    if(!t[i]) cnt++;
    else cnt = 0;

    if(cnt == 2*s + 1){
      i -= s;
      cout << i/60 << ' ' << i%60 << endl;
      break;
    }
  }
}
