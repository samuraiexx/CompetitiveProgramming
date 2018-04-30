#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int INF = 0x3f3f3f3f;

const int N = 1e5 + 5;

int ai[N], bi[N];


int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    int s;
    vector<pair<int, int>> s1, s2;
    cin >> s;
    for(int i = 0; i < s; i++){
      int d, a, b;
      cin >> d >> a >> b;
      ai[i] = d + a;
      bi[i] = d - b;
    }

    int p1 = 0, p2 = 0;
    for(int i = 1; i < s; i++){
      if(ai[i] != ai[i - 1]){
        s1.push_back({p1, i - 1});
        p1 = i;
      }
      if(bi[i] != bi[i - 1]){
        s2.push_back({p2, i - 1});
        p2 = i;
      }
    }
    s1.push_back({p1, s - 1});
    s2.push_back({p2, s - 1});

    //for(auto p : s1) db(p.st _ p.nd);
    //cout << endl;
    //for(auto p : s2) db(p.st _ p.nd);

    map<int, set<int>> m;
    for(auto p : s1){
      auto it = upper_bound(s2.begin(), s2.end(), make_pair(p.nd + 1, INF));
      int sz = p.nd - p.st + 1;
      if(it != s2.begin() and (--it)->st > p.st and it->st <= p.nd + 1)
        sz = max(sz, it->nd - p.st + 1);
      m[sz].insert(p.st);
    }
    for(auto p : s2){
      auto it = upper_bound(s1.begin(), s1.end(), make_pair(p.nd + 1, INF));
      int sz = p.nd - p.st + 1;
      if(it != s1.begin() and (--it)->st > p.st and it->st <= p.nd + 1)
          sz = max(sz, it->nd - p.st + 1);
      m[sz].insert(p.st);
    }

    while(m.size() > 1) m.erase(m.begin());

    cout << "Case #" << t << ": " << m.begin()->st << " " << m.begin()->nd.size() << endl;
  }
}
