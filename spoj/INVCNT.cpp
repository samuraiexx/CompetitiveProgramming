#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

#define db(x) cerr << #x << " = " << x << endl;
#define _ << ", " <<

int v[N], tmp[N];

int merge_sort(int l, int r){
  if(l == r) return 0;

  int inv = 0;
  int mid = (l + r)/2;
  inv = merge_sort(l, mid) + merge_sort(mid + 1, r);

  int i = l, j = mid + 1;
  int k = 0;

  while(i <= mid and j <= r){
    if(j > r) tmp[k] = v[i], i++;
    else if(i > mid) tmp[k] = v[j], j++;
    else if(v[i] < v[j]) tmp[k] = v[i], i++;
    else tmp[k] = v[j], j++, inv += mid - i + 1;
    k++;
  }

  for(int i = l; i <= r; i++)
    cout << v[i] << ' ';
  cout << endl;

  for(int i = 0; i < k; i++)
    v[l + i] = tmp[i];

  return inv;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);

    printf("%d\n", merge_sort(0, n - 1));
  }
}
