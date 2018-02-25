#include<bits/stdc++.h>
using namespace std;
int pok[200];
int vit[200];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> pok[i];

  int i = 1;
  int j = 0;
  while(i < n){
    if(pok[j] < pok[i]) j = i;
    vit[j]++;
    i++;
  }
  for(int i = 0; i < n; i++)
    cout << vit[i] << " \n"[i == n - 1];
  return 0;
}
