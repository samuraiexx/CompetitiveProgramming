#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 1e5 + 5;

set<int> seq[12];
string nota[12];
int v[N];

int main(){
  for(int i = 0; i < 12; i++){
    seq[i].insert(i);
    seq[i].insert((i + 2)%12);
    seq[i].insert((i + 4)%12);
    seq[i].insert((i + 5)%12);
    seq[i].insert((i + 7)%12);
    seq[i].insert((i + 9)%12);
    seq[i].insert((i + 11)%12);
  }
  nota[0] = "do";
  nota[1] = "do#";
  nota[2] = "re";
  nota[3] = "re#";
  nota[4] = "mi";
  nota[5] = "fa";
  nota[6] = "fa#";
  nota[7] = "sol";
  nota[8] = "sol#";
  nota[9] = "la";
  nota[10] = "la#";
  nota[11] = "si";

  int n;
  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> v[i], v[i]--, v[i] = v[i]%12;

  for(int i = 0; i < 12; i++){
    bool ok = true;
    for(int j = 0; j < n; j++)
      ok = ok & seq[i].count(v[j]);
    if(ok) return cout << nota[i] << endl, 0;
  }

  cout << "desafinado" << endl;
}
