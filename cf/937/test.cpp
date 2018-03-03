#include <bits/stdc++.h>
using namespace std;
int check(string A){
  int t=0;
  for(int i=0;i<A.size()-1;i++){
    if((int) A[i+1]>(int) A[i]){t++;}}
  if(t==A.size()-1){return 1;}else{return 0;}
}
int main(){
  int n;
  scanf("%d",&n);
  cout << n << endl;
  vector<string>A(n);
  vector<int>B(n);
  cout << n << endl;
  for(int i=0;i<n;i++){
    cout << n << endl;
    cin >> A[i];
    B[i]=check(A[i]);}

  for(int i=0;i<n;i++){
    if(B[i]==1){cout<<A[i]<<": "<<"O\n";}else{cout<<A[i]<<": "<<"N\n";}}

  return 0;  
}
