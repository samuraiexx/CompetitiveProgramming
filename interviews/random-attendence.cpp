#include<bits/stdc++.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 

using namespace std;

void get_until(long long lim, vector<string> &ans, string cur){
  if(cur.size() and stoll(cur) > lim or cur[0] == '0') return;
  ans.push_back(cur);

  for(char c = '0'; c <= '9'; c++){
    cur.push_back(c);
    get_until(lim, ans, cur);
    cur.pop_back();
  }
}

vector<int> solve(int A, vector<int> &B) {
  vector<string> s;
  get_until(A, s, "");
  vector<int> ans;

  for(auto k : B)
    ans.push_back(stoll(s[k]));

  return ans;
}


int main(){
  int x, a;
  vector<int> B;
  cin >> a;
  while(cin >> x)
    B.push_back(x);

  auto v = solve(a, B);

  for(auto x : v)
    cout << x << endl;
}
