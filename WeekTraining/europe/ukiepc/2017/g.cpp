#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int ai[3], bi[3], af[3], bf[3];

bool ended(){
  return ai[0] == af[0] and ai[1] == af[1] and ai[2] == af[2]
     and bi[0] == bf[0] and bi[1] == bf[1] and bi[2] == bf[2];
}

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  cin >> ai[0] >> ai[1] >> ai[2];
  cin >> af[0] >> af[1] >> af[2];
  cin >> bi[0] >> bi[1] >> bi[2];
  cin >> bf[0] >> bf[1] >> bf[2];

  cout << '(' << ai[0] << ' ' << ai[1] << ' ' << ai[2] << ") ";
  cout << '(' << bi[0] << ' ' << bi[1] << ' ' << bi[2] << ")\n";

  for(int i = 0; !ended(); i++){
    i = i%3;
    int k = (i + 1)%3;

    int ad = af[i] == ai[i] ? 0 : (af[i] - ai[i])/abs(af[i] - ai[i]); //a direction
    int bd = bf[k] == bi[k] ? 0 : (bf[k] - bi[k])/abs(bf[k] - bi[k]); //b direction

    while(ai[i] != af[i] or bi[k] != bf[k]){
      if(ai[i] != af[i]) ai[i] += ad;
      if(bi[k] != bf[k]) bi[k] += bd;

      if(ai[0] == bi[0] and ai[1] == bi[1] and ai[2] == bi[2])
        ai[i] -= ad, ai[(3 + i - 1)%3]++;

      cout << '(' << ai[0] << ' ' << ai[1] << ' ' << ai[2] << ") ";
      cout << '(' << bi[0] << ' ' << bi[1] << ' ' << bi[2] << ")\n";
    }

    //db(ai[0] _ ai[1] _ ai[2]);
    //db(bi[0] _ bi[1] _ bi[2]);
  }
}
