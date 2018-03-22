#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

const int N = 1e3;
char s2[N];

int main(){
  int n = 0;
  bool rm;
  char c;
  while(scanf("%c", &c), c != ':') n *= 10, n += c - '0';

  vector<string> ans;

  int cnt1 = 0, cnt2 = 0, cnt3 = 0;

  string s;
  cin >> s >> c;
  if(s[0] == 'T') rm = true;
  else rm = false;

  while(fgets(s2, N, stdin)){
    int i;
    for(i = 0; s2[i] == ' '; i++);
    char *s3 = (s2 + i);
    if(s3[0] == ']'  or s3[0] == '['){ cnt1++; continue; }

    cnt2++;
    if(s3[0] == '\n' or s3[1] == '^M'){
      cnt3++;
      if(rm) continue;
    }
    s3[strlen(s3) - 1] = '\0';
    ans.pb(s3);
  }

  cnt1 = (cnt1 - 1)/2;

  cnt3--;

  int sz = (ans.size() - 1 + n)/n;
  int wsz = sz*n - ans.size();
  cout << sz << endl;
  cout << sz - cnt1 << endl;

  if(rm) cout << wsz - cnt3 << endl;
  else cout << wsz << endl;

  if(rm) cout << wsz << endl;
  else cout << wsz + cnt3 << endl;

  cout << '[' << endl;
  for(int i = 0;i < ans.size();){
    cout << '[' << endl;
    for(int j = 0; j < n; j++, i++){
      if(i >= ans.size()) cout << endl;
      else cout << ans[i] << endl;
    }
    cout << ']' << endl;
  }
  cout << ']' << endl;
}
