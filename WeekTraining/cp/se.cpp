#include <iostream>
#include <functional>

using namespace std;

char buffer[1000001];

class node
{
public:
	int w;
	node* next[26];
	node(){
		w = 0;
		for(int i = 0; i < 26; i++)
			next[i] = NULL;
	}
	void add(int weight, char *buffer)
	{
		w = max(w, weight);
		if(buffer[0] == '\0')
			return;
		if(next[buffer[0] - 'a'] == NULL)
			next[buffer[0] - 'a'] = new node;
		next[buffer[0] - 'a']->add(weight, buffer + 1);
	}
	int query(char *buffer)
	{
		if(buffer[0] == '\0')
			return w;
		if(next[buffer[0] - 'a'] == NULL)
			return -1;
		return next[buffer[0] - 'a']->query(buffer + 1);
	}
};

int main()
{
	int n, q;
	node trie;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
	{
		int j, w;
		cin.ignore(); //ignore the \n
		char c = cin.get();
		for(j = 0; c != ' '; j++, c = cin.get())
			buffer[j] = c;
		buffer[j] = '\0';
		cin >> w;
		trie.add(w, buffer);
	}
	cin.ignore(); //ignore the \n
	for(int i = 0; i < q; i++)
	{
		int j, w;
		char c = cin.get();
		for(j = 0; c != '\n'; j++, c = cin.get())
			buffer[j] = c;
		buffer[j] = '\0';
		cout << trie.query(buffer) << '\n';
	}
	return 0;
}

