#include<bits/stdc++.h>
using namespace std;

void add(int p){}
void rem(int p){}

struct query { int i, l, r, ans; } qs[N];

bool c1(query a, query b) { return a.l/SQ == b.l/SQ ? a.r < b.r : a.l < b.l; }
bool c2(query a, query b) { return a.i < b.i; }


int main(){
}
