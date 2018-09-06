#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;
int amt[26];
int cnt[26];
bool use[N];

int m;
string s;

bool allin(int x){
  for(int j = 0; j <= x; j++)
    if(amt[j] > 0) return true;
  return false;
}

bool func(int x){
  memset(amt, 0, sizeof amt);
  for(int i = 0; i < m; i++)
    amt[s[i] - 'a']++;

  if(!allin(x)) return false;

  for(int i = m; i < s.size(); i++){
    amt[s[i - m] - 'a']--, amt[s[i] - 'a']++;
    if(!allin(x)) return false;
  }
  return true;
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  cin >> m >> s;

  for(auto c : s)
    cnt[c - 'a']++;

  int i = 0, j = 26;
  while(i != j){
    int mid = (i + j)/2;
    if(func(mid)) j = mid;
    else i = mid + 1;
  }

  int ans = i;
  int lst = -1, lst2 = -1;

  memset(amt, 0, sizeof amt);
  for(int i = 0; i < m; i++){
    amt[s[i] - 'a']++;
    if(s[i] == 'a' + ans) lst = i;
  }

  if(!allin(ans - 1)) use[lst] = true, lst2 = lst;

  for(int i = m; i < s.size(); i++){
    amt[s[i - m] - 'a']--, amt[s[i] - 'a']++;
    if(s[i] == 'a' + ans) lst = i;
    if(!allin(ans - 1) and lst2 <= i - m)
      use[lst] = true, lst2 = lst;
  }

  for(int i = 0; i < j; i++)
    for(int k = 0; k < cnt[i]; k++)
      cout << (char)(i + 'a');

  for(int i = 0; i < s.size(); i++)
    if(use[i]) cout << (char)('a' + ans);
  cout << '\n';
}
