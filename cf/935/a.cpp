#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl;
#define _ << ", " <<;

int main(){
  int n;
  cin >> n;
  int amt = 0;
  for(int i = 2; i <= n; i++)
    if(n%i == 0) amt++;
  cout << amt << endl;
}
