#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const nt N = 5e3 + 5;

int as[N], bs[N];

int main(){
  string s;
  cin >> s;

  for(int i = 0; i < s.size(); i++)
    if(s[i] == 'a') as[i]++;
    else bs[i]++;

  for(int i = 1; i < s.size(); i++)
    as[i] += as[i - 1], bs[i] += bs[i - 1];

  int ans = 0;
  for(int i = 1; i < s.size(); i++)
    ans = max(ans, 
}
