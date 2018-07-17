#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;

int c[N];
int n, q, t, b[20];

int main(){
  scanf("%d", &q);

  while(q--) {
    memset(c, 0x3f, sizeof c);
    scanf("%d %d", &n, &t);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);

    c[0] = 0;
    for(int i=0; i<N; i++) {
      for(int j=0; j<n; j++) if(b[j] > 0 and b[j] <= i and ~c[i-b[j]]) {
        if(c[i] == -1) c[i] = INF;
        c[i] = min(c[i], 1 + c[i - b[j]]);
      }
    }

    for(int i=3601; i<N; i++) c[3600] = min(c[3600], ~c[i] ? INF : c[i]);

    for(int i=t; i>=0; i--) {
      for(int j=0; j<n; j++) if(b[j] < 0 and i-b[j] <= 3600 and ~c[i-b[j]]) {
        if(c[i] == -1) c[i] = INF;
        c[i] = min(c[i], 1 + c[i - b[j]]);
      }
    }
    int p;
    for(p = t; p <= 3600; p++) {
      if(~c[p]) break;
    }

    printf("%d %d\n", c[p], p - t);
  }
}
