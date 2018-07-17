#include <iostream>
#include <functional>
#include <cmath>
using namespace std;

int main()
{
    int t;
    for(int i = 0; i < t; i++)
    {
        int x, l, n;
        cin >> x >> l >> n;
	if( n == 0 )
		cout << 0 << endl;
        if( n >= 64)
            {
                cout << n << endl;
                break;
            }
        cout << ceil(l/(double)((long long)1 << n)) << endl;
    }    
    return 0;
}

