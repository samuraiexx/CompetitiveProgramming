#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int rem[N];
bool vis[N];
string s, t;
int pnt = -1;

bool ver(int x){
  while(pnt < x) vis[rem[++pnt]] = 1;
  while(pnt > x) vis[rem[pnt--]] = 0;

  int i, j;
  bool ok = 0;
  for(i = 0, j = 0; !ok and j < s.size(); i++)
    while(j < s.size()){
      if(!vis[j] and t[i] == s[j]) {
        if(i == t.size() - 1) ok = 1;
        j++;
        break;
      }
      j++;
    }
  return ok;
}

int main(){
  cin >> s >> t;
  for(int i = 0; i < s.size(); i++) cin >> rem[i], rem[i]--;

  int i = 0, j = s.size() - 1;
  while(i != j){
    int mid = (i + j)/2;
    if(ver(mid)) i = mid + 1;
    else j = mid;
  }
  cout << i << endl;
}
