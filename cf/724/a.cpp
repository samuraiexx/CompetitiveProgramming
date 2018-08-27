#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

int week(string s){
  if(s == "monday")
    return 0;
  if(s == "tuesday")
    return 1;
  if(s == "wednesday")
    return 2;
  if(s == "thursday")
    return 3;
  if(s == "friday")
    return 4;
  if(s == "saturday")
    return 5;
  if(s == "sunday")
    return 6;
}

int main(){
  string s1, s2;
  cin >> s1 >> s2;

  int w1 = week(s1), w2 = week(s2);

  if(w2 == (w1 + 30)%7 or
      w2 == (w1 + 31)%7 or
      w2 == (w1 + 28)%7) cout << "YES" << endl;
  else cout << "NO" << endl;
}
