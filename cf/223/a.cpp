#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

void clear(stack<pair<char, int>> &st){
  stack<pair<char, int>> tmp;
  swap(st, tmp);
}

int main(){
  string s;
  stack<pair<char, int>> st;
  cin >> s;
  int amt = 0, l = 1e9, r = 0;
  int mx = 0, fl, fr;

  for(int i = 0; i < s.size(); i++){
    char c = s[i];
    if(c == '[' or c == '(') st.push({c, i});
    else{
      if(c == ']'){
        if(st.size() and st.top().st == '[') l = min(l, st.top().nd), r = i, amt++, st.pop();
        else amt = 0, clear(st), l = 1e9;
      }
      else if(c == ')')
        if(st.size() and st.top().st == '(') l = min(l, st.top().nd), r = i, st.pop();
        else amt = 0, clear(st), l = 1e9;
    }

    if(amt > mx and l < r)
      mx = amt, fl = l, fr = r;
  }
  
  cout << mx << endl;
  if(mx){
    for(int i = fl; i <= fr; i++) cout << s[i];
    cout << endl;
  }
}
