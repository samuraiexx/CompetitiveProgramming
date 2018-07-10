#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int kmp[N];

void kmppre(string &s){
  kmp[0] = -1;
  for(int i = 0, j = -1; i < s.size(); kmp[++i] = ++j)
    while(j >= 0 and s[i] != s[j])
      j = kmp[j]; 
}

bool eval(string &s, string &p){
  int i = 0, j = 0;
  while(1){
    if(j == p.size()) return true;
    if(i == s.size()) return false;
    if(s[i] == p[i]) i++, j++;
    else if(j == 1) i++;
    else j = 1;
  }
}



int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    string s;
    cin >> s;
    kmppre(s);

    int j = 0;
    for(int i = 1; i < s.size(); i++)
      if(kmp[i] > 0){ j = i - 1; break; }
    
    string ans = "impossible";
    if(j > 0){
      ans = "";
      for(int i = 0; i < j; i++)
        ans.push_back(s[i]);
      ans = ans + s;

      if(eval(ans, s))
        ans = "impossible";
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
