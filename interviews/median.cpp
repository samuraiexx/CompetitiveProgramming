#include<bits/stdc++.h>
using namespace std;

double median(const vector<int> &A, const vector<int> &B) {
  int i = 0, j = A.size() - 1;
  int t = A.size() + B.size();

  while(i < j){
    int m = (i + j)/2;
    if(B.size() <= t - m - 2 or B[t - m - 2] > A[m])
      i = m + 1;
    else j = m;
  }
  i--;

  if(i > 0 and A[i] >= B[t - i - 2])
    if(t%2 == 1) return A[i];
    else{
      int x = B[min((int)B.size() - 1, t - i - 2)];
      if(x > A[i])
        if(i + 1 != A.size()) return min(x, A[i + 1]);
        else return x;
      else return A[i + 1];
    }

  i = 0, j = B.size() - 1;
  while(i < j){
    int m = (i + j)/2;
    if(A.size() <= t - m - 2 or A[t - m - 2] > B[m])
      i = m + 1;
    else j = m;
  }
  i--;

  if(t%2 == 1) return B[i];
  else {
      int x = A[min((int)A.size() - 1, t - i - 2)];
      if(x > B[i])
        if(i + 1 != B.size()) return min(x, B[i + 1]);
        else return x;
      else return B[i + 1];
  }
}


int main(){
  cout << median({-37, -9, 10, 19}, {-29, 18, 46}) << endl;
}
