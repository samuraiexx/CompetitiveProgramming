#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 5e3 + 5;
char tmp[N];

class BigInt{
public:
  string x;
  BigInt():x("0"){}
  BigInt(string x):x(x){}
  BigInt(int x){
    sprintf(tmp, "%d", x);
    this->x = tmp;
  }

  BigInt operator+(BigInt b){
    string s;
    int i = b.x.size() - 1;
    int j = x.size() - 1;
    int goes = 0;
    while(i >= 0 or j >= 0){
      int y;
      if(i < 0) y = (x[j--] - '0');
      else if(j < 0)  y = (b.x[i--] - '0');
      else y = (b.x[i--] - '0') + (x[j--] - '0');
      y += goes;
      goes = y/10;
      s = (char)(y%10 + '0') + s;
    }
    if(goes) s = (char)(goes + '0') + s;
    return BigInt(s);
  }
};

BigInt fib[N];

int main(){
  fib[1] = BigInt(1);
  for(int i = 2; i < N; i++)
    fib[i] = fib[i - 1] + fib[i - 2];

  int n;
  while(cin >> n)
    cout << "The Fibonacci number for " << n << " is " << fib[n].x << endl;
}
