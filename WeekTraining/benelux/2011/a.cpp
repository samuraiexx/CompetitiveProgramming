#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const double pi = acos(-1);
const double EPS = 1e-9;
const int N = 2e3 + 5;

int dead[N];
int in[N];

struct line{
  double pos;
  bool ed;
  int id;
  bool operator<(line b){
    if(abs(pos - b.pos) > EPS) return pos < b.pos;
    return ed < b.ed;
  }
};


int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    vector<line> bal;
    cin >> n;

    if(n == 0) { cout << 0 << endl; continue; }

    for(int i = 0; i < n; i++){
      int x, y, r;
      cin >> x >> y >> r;

      double t = asin(r/(double)hypot(x, y));
      double arc = atan2(y, x);
      if(arc < 0) arc += 2*pi;

      bal.push_back({arc + t, true, i});
      if(bal.back().pos > 2*pi) bal.back().pos -= 2*pi;

      bal.push_back({arc - t, false,  i});
      if(bal.back().pos < 0) bal.back().pos += 2*pi;
    }

    sort(bal.begin(), bal.end());

    int bst = 0x3f3f3f3f;


    n = 2*n;
    for(int i = 0; i < bal.size(); i++){
      int amt = 1;

      memset(dead, 0, n*sizeof(int));
      memset(in, 0, n*sizeof(int));

      for(int j = 1; j < bal.size(); j++){
        line &b = bal[(i + j)%n];
        if(!b.ed) in[b.id] = true;
        else if(!in[b.id]) dead[b.id] = true;
      }

      vector<int> in;

      for(int j = 0; j < bal.size(); j++){
        line &b = bal[(i + j)%n];
        if(dead[b.id]) continue;
        if(!b.ed) in.push_back(b.id);
        else {
          amt++;
          for(auto id : in) dead[id] = true;
          in.clear();
        }
      }
      bst = min(bst, amt);
    }

    cout << bst << endl;
  }
}
