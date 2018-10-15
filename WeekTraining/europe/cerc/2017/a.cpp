#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;
const int N = 55;
char g[N][15];
int amt[N];
int amt2[2];
int r, n;

struct seat{
  int row;
  char column;
  bool after;
  int dist;
  bool right;
  bool BH, E, AI, CG, DF;

  seat(int row, char column):row(row), column(column){
    after = (row == r/2 + 3 or row == 2);
    dist = min({abs(row - 1), abs(row - r/2 - 2), abs(row - r - 3)}); 
    right = (column > 'e');
    BH = (column  == 'b' or column == 'h');
    E = (column  == 'e');
    AI = (column  == 'a' or column == 'i');
    CG = (column  == 'c' or column == 'g');
    DF = (column  == 'd' or column == 'f');
  }

  bool operator<(const seat &b)const {
    if(after != b.after) return b.after;
    if(amt[row] != amt[b.row]) return amt[row] > amt[b.row];
    if(dist != b.dist) return dist > b.dist;
    if(row != b.row) return row > b.row;
    if(DF != b.DF) return b.DF;
    if(CG != b.CG) return b.CG;
    if(AI != b.AI) return b.AI;
    if(E != b.E) return b.E;
    if(BH != b.BH) return b.BH;
    if(amt2[right] != amt2[b.right]) return amt2[right] > amt2[b.right];
    return right;
  }
};

int column(char c){
  return c - 'a' + (c > 'c') + (c > 'f');
}

void add(seat s, char c){
  if(s.column != 'e') amt2[s.right]++;
  amt[s.row]++;
  g[s.row][column(s.column)] = c;
}

int main(){
  vector<seat> sv;
  cin >> r >> n;
  for(int i = 1; i <= r + 3; i++){
    int k = 0;
    for(int j = 0; j < 11; j++){
      cin >> g[i][j];
      if(g[i][j] == '-' or g[i][j] == '#'){
        auto s = seat(i, k + 'a');
        if(g[i][j] == '#') add(s, '#');
        else sv.pb(s);
        k++;
      }
    }
  }

  for(int i = 0; i < n; i++){
    sort(sv.begin(), sv.end());
    add(sv.back(), 'a' + i);
    sv.pop_back();
  }

  for(int i = 1; i <= r + 3; i++){
    for(int j = 0; j < 11; j++)
      cout << g[i][j];
    cout << '\n';
  }
}
