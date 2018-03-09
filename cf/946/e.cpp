#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
const int N = 2e5 + 5;

bool amt[N][10];

int main(){
  int t;
  cin >> t;
  while(t--){
    memset(amt, 0, sizeof amt);

    string s;
    cin >> s;
    int n = s.size();
    if(n%2 == 1) {
      for(int i = 0; i < n - 1; i++)
        cout << 9;
      cout << endl;
      continue;
    }

    amt[0][s[0] - '0'] ^= 1;

    for(int i = 1; i < n; i++){
      for(int j = 0; j < 10; j++)
        amt[i][j] = amt[i - 1][j];
      amt[i][s[i] - '0'] ^= 1;
    }

    int i;
    for(i = n - 1; i > 0; i--){
      int x = 0;
      if(s[i] == '0') continue;

      amt[i][s[i] - '0'] ^= 1;
      amt[i][s[i] - '1'] ^= 1;

      for(int j = 0; j < 10; j++) x += amt[i][j];

      amt[i][s[i] - '0'] ^= 1;
      amt[i][s[i] - '1'] ^= 1;

      if(x <= n - i - 1) break;
    }

    if(i == 0 and s[0] == '1') {
      for(int i = 0; i < n - 2; i++)
        cout << 9;
      cout << endl;
      continue;
    }

    amt[i][s[i] - '0'] ^= 1;
    amt[i][s[i] - '1'] ^= 1;

    s[i]--;

    vector<char> st;

    for(int j = 0; j < 10; j++) if(amt[i][j]) st.pb('0' + j);
    while(st.size() + i + 1 < n) st.pb('9');

    sort(st.begin(), st.end(), greater<char>());

    for(int j = 0; j <= i; j++)
      cout << s[j];

    for(auto c : st) cout << c;
    cout << endl;
  }
}

