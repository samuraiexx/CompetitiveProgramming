#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 105;
string s[N];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> s[i];

  int bst = 0;

  for(char i = 'a'; i <= 'z'; i++){
    for(char j = i + 1; j <= 'z'; j++){
      int cnt = 0;
      for(int k = 0; k < n; k++){
        bool ok = true;
        for(auto c : s[k])
          if(c != i and c != j)
            ok = false;

        if(ok) cnt += s[k].size();
      }

      bst = max(bst, cnt);
    }
  }

  cout << bst << endl;

}
