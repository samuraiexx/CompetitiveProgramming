#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 

int main(){
  int n;
  while(cin >> n, n){
    stack<int> st;
    bool ok = 1;
    int i = 1;

    for(int j = 0; j < n; j++){
      int x;
      cin >> x;

      if(x == i) i++;
      else st.push(x);

      while(st.size() and st.top() == i)
        st.pop(), i++;
    }

    if(st.size()) ok = 0;

    if(ok) cout << "yes\n";
    else cout << "no\n";
  }
}
