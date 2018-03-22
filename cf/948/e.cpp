#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;

int sbc[N], sras[N];
int tbc[N], tras[N];

int main(){
  string s, t; // obtain t from s
  cin >> s >> t;
  for(int i = 0; i < s.size(); i++){
    sbc[i + 1] = sbc[i] + (s[i] == 'B' or s[i] == 'C');
    if(s[i] == 'A') sras[i + 1] = sras[i] + 1;
  }

  for(int i = 0; i < t.size(); i++){
    tbc[i + 1] = tbc[i] + (t[i] == 'B' or t[i] == 'C');
    if(t[i] == 'A') tras[i + 1] = tras[i] + 1;
  }

  int q;
  cin >> q;
  while(q--){
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    i1--, i2--;
    int ra1 = min(sras[j1], j1 - i1);
    int ra2 = min(tras[j2], j2 - i2);

    int bc1 = sbc[j1] - sbc[i1];
    int bc2 = tbc[j2] - tbc[i2];

    if(ra2%3 != ra1%3) bc1 += 2;

    if(ra2 > ra1 or ra2 == ra1 and bc1 == 0 and bc2 > 0)
      cout << 0;
    else if(bc1 > bc2 or bc1%2 != bc2%2) cout << 0;
    else cout << 1;
  }
  cout << endl;
}
