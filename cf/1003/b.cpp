#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  int a, b, x;
  cin >> a >> b >> x;

  string ans;
  bool s;
  if(a > b){
    s = false;
    ans.push_back('0'), a--;
  } else{
    s = true;
    ans.push_back('1'), b--;
  }

  for(int i = 0; i < x; i++){
    s = !s;
    if(s) ans.push_back('1'), b--;
    else ans.push_back('0'), a--;
  }

  bool f1 = false, f2 = false;

  for(auto c : ans){
    cout << c;

    if(c == '0' and f1 == false)
      for(int i = 0; i < a; i++)
        cout << 0, f1 = true;

    if(c == '1' and f2 == false)
      for(int i = 0; i < b; i++)
        cout << 1, f2 = true;
  }

  cout << endl;
}
