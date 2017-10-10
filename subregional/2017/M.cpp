#include <iostream>

using namespace std;

int main(){
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	cout << 2*min(a2 + 2*a3, min(a1 + a3, 2*a1 + a2)) << endl;
	return 0;
}
