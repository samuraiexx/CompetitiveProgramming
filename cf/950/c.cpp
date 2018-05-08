#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int main(){
  string s;
  cin >> s;

  vector<vector<int>*> z, o;
  for(int i = 0; i < s.size(); i++){
    char c = s[i];
    if(c == '0'){
      if(o.size()){
        o.back()->push_back(i + 1);
        z.push_back(o.back());
        o.pop_back();
      }else{
        z.push_back(new vector<int>(1, i + 1));
      }
    } else if(c == '1'){
      if(!z.size()) return cout << -1 << endl, 0;
        z.back()->push_back(i + 1);
        o.push_back(z.back());
        z.pop_back();
    }
  }
  if(o.size()) return cout << -1 << endl, 0;

  //db(z.size() _ o.size());
  cout << z.size() << endl;
  for(auto v : z){
    cout << v->size();
    for(auto x : *v)
      cout << ' ' <<  x;
    cout << endl;
  }
}
