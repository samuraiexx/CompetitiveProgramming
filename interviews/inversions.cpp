#include<bits/stdc++.h>
using namespace std;

int countInversions(vector<int> &A) {
  if(A.size() == 1) return 0;
  int inv = 0;
  vector<int> fh, sh;
  for(int i = 0; i < A.size(); i++)
    if(i < A.size()/2) fh.push_back(A[i]);
    else sh.push_back(A[i]);

  inv += countInversions(fh) + countInversions(sh);

  int i = 0, j = 0, k = 0;
  while(k < A.size()){
    if(i == fh.size()) A[k++] = sh[j++];
    else if(j == sh.size()) A[k++] = fh[i++];
    else if(fh[i] <= sh[j]) A[k++] = fh[i++];
    else A[k++] = sh[j++], inv += fh.size() - i;
  }
  return inv;
}


int main(){
  vector<int> v = {4, 3};
  cout << countInversions(v) << endl;
}
