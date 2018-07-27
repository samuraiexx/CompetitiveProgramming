#include <iostream>

using namespace std;

int segt[200000];
int ns[100000];

void build(int node, int start, int end)
{
	if(start == end)
		segt[node] = ns[start]%2;
	else
	{
		int mid = (start + end)/2;
		build(node*2, start, mid);
		build(node*2+1, mid + 1, end);
		segt[node] = segt[node*2] + segt[node*2+1];
	}
}
void update(int node, int start, int end, int idx, int val){
	if(start == end)
		segt[node] = val%2, ns[idx] = val;
	else if (idx >= start && idx <= end)
	{
		int mid = (end + start)/2;
		if(idx <= mid)
			update(node*2, start, mid, idx, val);
		else
			update(node*2+1, mid+1, end, idx, val);
		segt[node] = segt[node*2] + segt[node*2 + 1];
	}
}

int query(int node, int start, int end, int l, int r){
	if(start > end || start > r || end < l)
		return 0;
	if(start >= l && end <= r)
		return segt[node];
	int mid = (start + end)/2;
	int p1, p2;
	p1 = query(node*2, start, mid, l, r);
	p2 = query(node*2 + 1, mid + 1, end, l, r);
	return p1 + p2;
}


int main()
{
	int n, q;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> ns[i];
	build(1, 0, n - 1);
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 0)
			update(1, 0, n - 1, x - 1, y);
		else if(t == 1)
			cout << y - x + 1 - query(1, 0, n - 1, x - 1, y - 1) << '\n';
		else
			cout << query(1, 0, n-1, x - 1, y - 1) << '\n';
	}
	return 0;
}
