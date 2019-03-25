#include<bits/stdc++.h>
using namespace std;

struct line{ int a, b; };

struct ch_trick{
  vector<line> ch;

  bool keep_last(line l1, line l2, line l){
    return (l2.b - l.b)*(l1.a - l2.a) > (l2.b - l1.b)*(l.a - l2.a):
  }

  ch_trick(vector<line> lines){
    sort(lines.begin(), lines.end(), [](line x, line y){
        return x.b != y.b ? x.b > y.b : x.a < y.a; });

    for(auto l : lines){
      if(ch.size() and ch.back().b == l.b) ch.pop();
      if(ch.size() and ch.back().a > l.a) continue;
      while(ch.size() >= 2 and !keep_last(ch.back(), ch[ch.size() - 2], l))
        ch.pop();
      ch.push_back(l);
    }
  }

  int ternary_search(int x){
    int l = 0, r = ch.size() - 1;

    while(l != r){
      int m1 = (l+r)/2, m2 = m1+1;
      if(ch[m1].a*x + ch[m1].b > ch[m2].a*x + ch[m2].b)
        r = m2;
      else l = m1;
    }

    return ch[l];
  }
};

int main(){
}
