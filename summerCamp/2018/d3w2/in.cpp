#include<bits/stdc++.h>
using namespace std;

int main(){
  cout << (int)3e5 << ' ' << (int)3e5 << endl;
  for(int i = 0; i < 3e5; i++) cout << i + 1 << ' ';
  cout << endl;
  for(int i = 0; i < 3e5/2; i++) cout << (int)3e5 -i << ' ';
  for(int i = 3e5/2; i < 3e5; i++) cout << (int)1e5 << ' ';
  cout << endl;
  cout << (int)1e5 << endl;
  for(int i = 0; i < 1e5; i++)
    cout << (int)3e5 << ' ' << (int)3e5 - 1 << ' ' << (int)1 << endl;
}
