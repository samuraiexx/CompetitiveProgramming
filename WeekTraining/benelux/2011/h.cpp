#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define st first
#define nd second
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
typedef long long ll;

struct Pirate{
  int time;
  int speed;

  int t1, t2, t3, t4;

  bool operator<(const Pirate p) const {
    return time != p.time ? time > p.time : speed < p.speed;
  }
};

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, p;
    cin >> n >> p;

    priority_queue<Pirate> pir, com;
    for(int i = 0; i < p; i++){
      Pirate p;
      cin >> p.t1 >> p.t2 >> p.t3 >> p.t4;
      p.time = 0;
      p.speed = -i;

      pir.push(p);
    }

    int time = 0;

    while(pir.size() or com.size()){
      if(pir.empty() or com.size() and
         (com.top().time <= pir.top().time or com.top().time <= time)){
        Pirate p = com.top(); com.pop();
        //db("commercial" _ p.time _ time _ p.t1);
        time = max(time, p.time);

        p.time = time + p.t3 + p.t4;
        p.speed = p.t4;
        time += p.t3;

        pir.push(p);
      }else{
        Pirate p = pir.top(); pir.pop();

        if(n) n--;
        else continue;

        //db("pirate" _ p.time _ time _ p.t1);
        time = max(time, p.time);

        p.time = time + p.t1 + p.t2;
        p.speed = p.t2;
        time += p.t1;
        com.push(p);
      }
    }

    cout << time << endl;
  }
}
