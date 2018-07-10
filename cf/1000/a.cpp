#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int ch(string s1, string s2){
  if(s1.size() > s2.size()) swap(s1, s2);

  map<char, int> c2;

  for(auto c : s2)
    c2[c]++;

  int cnt = 0;

  for(auto c : s1)
    if(c2[c] > 0) s2[c]--;
    else cnt++;

  return cnt + s2.size() - s1.size();
}

int main(){
  int n;
  multiset<string> st;
  multiset<string> v;

  cin >> n;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    st.insert(s);
  }

  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    v.insert(s);
  }
  int ans = 0;

  for(int i = 0; i < 5 and v.size(); i++){
    bool again = false;

    for(auto it1 = v.begin(); !again and it1 != v.end(); it1++)
      for(auto it2 = st.begin(); !again and it2 != st.end(); it2++)
        if(ch(*it1, *it2) == i)
          v.erase(it1), st.erase(it2), ans += i, again = true;
    if(again) i--;
  }

  cout << ans << endl;
}
