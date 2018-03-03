#include<bits/stdc++.h>
using namespace std;

int find(string &s, string &p){
  int cnt = 0;
  for(int i = 0; i <= (int)s.size() - (int)p.size(); i++)
    for(int j = 0; j < p.size(); j++)
      if(s[i + j] != p[j]) break;
      else if(j == p.size() - 1) cnt++;
  return cnt;
}

int main(){
  vector<string> cmp = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
  int cnt = 0;
  string s;
  cin >> s;
  for(auto &p : cmp)
    cnt += find(s ,p);
  if(cnt == 1) cout << "YES" << endl;
  else cout << "NO" << endl;
}
