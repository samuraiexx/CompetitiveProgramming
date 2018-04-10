#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e7 + 5;;
bool nok[N];
int siev[N];

void zerate(int x){
  while(x != 1){
    if(!nok[siev[x]]) for(int i = siev[x]; i < N; i += siev[x])
      nok[i] = true;
    x /= siev[x];
  }
}

int main(){
  int n;
  vector<int> ans;
  cin >> n;
  bool eq = true;

  for(int i = 2; i < N; i++)
    if(!siev[i]) for(int j = i; j < N; j += i) siev[j] = i;

  int j = 2;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(eq and !nok[x]){
      ans.pb(x);
      zerate(x);
    }else{
      if(eq){
        eq = false;
        for(int i = x + 1; i < N; i++)
          if(!nok[i]) { zerate(i); ans.pb(i); break; }
      }else{
        while(nok[j]) j++;
        zerate(j);
        ans.pb(j);
      }
    }
  }

  for(auto x : ans) cout << x << ' ';
  cout << endl;
}
