#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  char c;
  scanf("%d%c", &n, &c);
  for(int i = 0; i < n; i++){
    string s;
    bool ok = 1;
    stack<char> st;

    while(scanf("%c", &c), c != '\n') s.push_back(c);

    for(auto c : s){
      if(c == '(' or c == '[') st.push(c);

      if(c == ')')
        if(st.size() and st.top() == '(') st.pop();
        else { ok = 0; break; }

      if(c == ']')
        if(st.size() and st.top() == '[') st.pop();
        else { ok = 0; break; }
    }

    if(ok and st.size() == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
