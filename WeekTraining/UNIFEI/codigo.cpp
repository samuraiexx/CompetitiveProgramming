#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<char, char> m;
	m['B'] = m['P'] = m['F'] = m['V'] = '1';
	m['C'] = m['S'] = m['X'] = m['Z'] = '2';
	m['K'] = m['G'] = m['J'] = m['Q'] = '3';
	m['D'] = m['T'] = '4';
	m['L'] = '5';
	m['M'] = m['N'] = '6';
	m['R'] = '7';
	
	string s;
	for(int i = 0; i < 9; i++)
		cout << ' ';
	cout << "NOME";
	
	for(int i = 0; i < 21; i++)
		cout << ' ';
	cout << "CODIGO LOUCO DO ROBERTO" << endl;
	cout << "---------------------------------------------------------\n";
	while(cin >> s)
	{
		for(int i = 0; i < 9; i++)
			cout << ' ';
		cout << s;
		string t(s);
		for(int i = 0; i < t.size(); i++)
			if(i != 0 && i != s.size() - 1)
				if(m.count(s[i]) && s[i - 1] != s[i])
					t[i] = m[s[i]];
				else
					t[i] = '0';
		for(int i = 1, j = 2; j < t.size(); i++, j++)
		{
			while(i < t.size() - 1 && t[i] != '0')
				i++;
			while(j < t.size() - 1 &&( t[j] == '0' || j <= i))
				j++;
			if(i < t.size() - 1 && j < t.size() - 1)
				swap(t[i], t[j]);
		}
		for(int i = 0; i < 25 - s.size(); i++)
			cout << ' ';
		cout << t << endl;
	}
	for(int i = 0; i < 19; i++)
		cout << ' ';
	cout << "FIM DO PROGRAMA" << endl;
}
