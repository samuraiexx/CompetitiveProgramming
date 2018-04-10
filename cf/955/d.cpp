#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 5e5 + 5;
string s, t;
int n, m, k;

int bst[N];

// Knuth-Morris-Pratt - String Matching O(n+m)
int b[N]; 
int c[N], cx[N];

int d[N], dx[N];

void kmppre() {
  b[0] = -1;
  for (int i = 0, j = -1; i < k; b[++i] = ++j)
    while (j >= 0 and t[i] != t[j])
      j = b[j];
}

void kmp(int c[N], int cx[N]) {
  for (int i = 0, j = 0; i < n;) {
    while (j >= 0 and s[i] != t[j]) j=b[j];
    i++, j++;
    if(i >= k){
      if(j > c[i - 1]) c[i] = j, cx[i] = i;
      else c[i] = c[i - 1], cx[i] = cx[i - 1];
    }

    if (j == k) {
      j = b[j];
    }
  }
}

int main(){
  cin >> n >> m >> k;
  cin >> s >> t;

  kmppre();
  kmp(c, cx);
  memset(b, 0, sizeof b);
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());

  kmppre();
  kmp(d, dx);

  reverse(d + 1, d + n + 1);
  reverse(dx + 1, dx + n + 1);

  /*
  for(int i = 1; i <= n; i++) cout << c[i] << ' ';
  cout << endl;
  for(int i = 1; i <= n; i++) cout << cx[i] << ' ';
  cout << endl;
  cout << endl;
  for(int i = 1; i <= n; i++) cout << d[i] << ' ';
  cout << endl;
  for(int i = 1; i <= n; i++) cout << dx[i] << ' ';
  cout << endl;
  */

  for(int i = 1; i < n; i++) if(c[i] + d[i + 1] == m)
    return cout << "Yes\n" << cx[i] - k + 1 << ' ' << n - dx[i + 1] + 1 << endl, 0;

  cout << "No" << endl;
}
