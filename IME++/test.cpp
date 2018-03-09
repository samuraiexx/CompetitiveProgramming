#include <bits/stdc++.h>
#include <math.h>
#define db(x) cerr << #x << " = " << x << endl
#define _ << ", " << 
using namespace std;
int main()
{
  double PI=3.14159;
  double g=9.80665;
  int p1,p2,n;
  double h,vel,angulo,rad,alcance;

  scanf("%lf",&h);
  scanf("%d %d",&p1,&p2);
  scanf("%d",&n);
  while (n--)
  {
    scanf("%lf %lf",&angulo,&vel);

    rad=angulo*PI/180;
    db(angulo _ PI _ rad);
    alcance = vel*cos(rad)/g*(vel*sin(rad)+sqrt(vel*vel*sin(rad)*sin(rad)+2*g*h));
    printf("%lf\n",rad);
    if (alcance<p2 && alcance>p1)
      printf("%.5lf -> DUCK\n",alcance);
    else
      printf("%.5lf -> NUCK\n",alcance);
  }
}
