#include <iostream>
#include <algorithm>
 
using namespace std;
 
int lazy[1000001];
int tree[2000000];
int box[1000000];
 
 
void prop(int node, int start, int end)
{
	if(lazy[node])
	{
		tree[node] += lazy[node]*(end - start + 1);
		if(start != end)
		 {
			lazy[node*2] += lazy[node];
			lazy[node*2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start != end)
	{
		int mid = (start + end)/2;
		prop(node*2, start, mid);
		prop(node*2+1, mid + 1, end);
	}
	else
		box[start] = tree[node];
}
 
void rangeUpdate(int node, int start, int end, int l, int r, int val)
{
	if(lazy[node])
	{
		tree[node] += lazy[node]*(end - start + 1);
		if(start != end)
		 {
			lazy[node*2] += lazy[node];
			lazy[node*2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start > end || start > r || end < l)
		return;
	if(start == end)
		tree[node] += val;
	else if(start >= l && end <= r)
	{
		lazy[node*2] += val;
		lazy[node*2 + 1] += val;
		tree[node] += (end - start + 1)*val;
	}
	else
	{
		int mid = (start + end)/2;
		rangeUpdate(node*2, start, mid, l, r, val);
		rangeUpdate(node*2 + 1, mid + 1, end, l, r, val);
		tree[node] = tree[node*2] + tree[node*2 + 1];
		
	}
}
 
 
int main()
{
	int n, m, q;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		rangeUpdate(1, 0, n - 1, l - 1, r - 1, 1);
	}
	prop(1, 0, n - 1);
	cin >> q;
	sort(box, box + n, greater<int>());
	for(int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		cout << upper_bound(box, box+n, x, greater<int>()) - box << endl;
	}
	return 0;
}

