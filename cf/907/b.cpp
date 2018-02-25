#include<bits/stdc++.h>
using namespace std;
char m[10][10];

int main(){
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++){
            char c;
            cin >> c;
            m[i][j] = c;
            if(c != '.' and c != 'o' and c != 'x') j--;
        }

    int x, y;
    cin >> x >> y;
    x--, y--;
    x = x%3, y = y%3;

    bool ok = 0;
    for(int i = 3*x; i < 3*x + 3; i++)
        for(int j = 3*y; j < 3*y + 3; j++)
            if(m[i][j] == '.') m[i][j] = '!', ok = 1;
     
    if(!ok) for(int i = 0; i < 9; i++)
                for(int j = 0; j < 9; j++)
                if(m[i][j] == '.') m[i][j] = '!';

    for(int i = 0; i < 9; i++){
        if(i%3 == 0 and i > 0) cout << endl;
        for(int j = 0; j < 9; j++){
            if(j > 0 and j%3 == 0) cout << ' ';
            cout << m[i][j];
        }
        cout << endl;
    }
}

