#include<bits/stdc++.h>
using namespace std;
int days[25];
int m[] = {31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30 ,31};
bool pnt[12];

int main(){
    int n, x = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> days[i];
        if(days[i] == 29) x++, days[i]--;
    }
    if(x > 1) return cout << "No" << endl, 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 12; j++)
            if(days[i] != m[(i + j)%12]) pnt[j] = true;

    for(int i = 0; i < 12; i++)
        if(!pnt[i]) return cout << "Yes" << endl, 0;

    cout << "No" << endl;
}
