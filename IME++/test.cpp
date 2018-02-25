#include<bits/stdc++.h>
using namespace std;
int main() {
int v[5]={0,1,2,3,5};
do {
	for (int i=0; i<5; i++)
		printf ("%d", v[i]);
	printf ("\n");
} while (next_permutation(v,v+5));
return 0;
}
