#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
#define pb push_back
#define st first
#define nd second
#define mp make_pair
typedef long long ll;
const int N = 5e3 + 5;

int x[N][26][26];
int ans[N][26];

int main(){
  string s;
  cin >> s;

  int n = s.size();

  for(int i = 0; i < n; i++)
    for(int j = 1; j < n; j++)
      x[j][s[i] - 'a'][s[(i + j)%n] - 'a']++;

  for(int i = 0; i < n; i++)
    for(int j = 1; j < n; j++)
      if(x[j][s[i] - 'a'][s[(i + j)%n] - 'a'] == 1) ans[j][s[i] - 'a']++;

  int tot = 0;
  for(int j = 0; j < 26; j++){
    int mx = 0;
    for(int i = 1; i < n; i++)
      mx = max(mx, ans[i][j]);

    tot += mx;
  }

  printf("%.12lf\n", tot/(double)n);
}
