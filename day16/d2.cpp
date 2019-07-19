#include <iostream>
#include <cstdio>
#include  <cstring>
#include  <algorithm>
using namespace std;
const int maxn = 70000;
int a[maxn];
int x, y;
struct tree {
	int mi;
	int ma;
};
tree T[maxn<<2];
void build(int rt, int l, int r)
{
	if (l == r) {
		T[rt].mi = a[l]; T[rt].ma = a[l]; return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build((rt << 1) + 1, mid + 1, r);
	T[rt].mi = min(T[rt << 1].mi, T[(rt << 1) + 1].mi);
	T[rt].ma = max(T[rt << 1].ma, T[(rt << 1) + 1].ma);
}
int query1(int rt, int l, int r, int x, int y)
{
	if (x <= l && r <= y) {
		return T[rt].ma;
	}
	int mid = (l + r) >> 1;
	if (y <= mid) return query1(rt << 1, l, mid, x, y);
	else if (x > mid) return query1((rt << 1) + 1, mid + 1, r, x, y);
	else return max(query1(rt << 1, l, mid, x, mid), query1((rt << 1) + 1, mid + 1, r, mid + 1, y));
}
int query2(int rt, int l, int r, int x, int y)
{
	if (x <= l && r <= y) {
		return T[rt].mi;
	}
	int mid = (l + r) >> 1;
	if (y <= mid) return query2(rt << 1, l, mid, x, y);
	else if (x > mid) return query2((rt << 1) + 1, mid + 1, r, x, y);
	else return min(query2(rt << 1, l, mid, x, mid), query2((rt << 1) + 1, mid + 1, r, mid + 1, y));
}
int main()
{
	int n, q;
	int x, y;

	while (scanf("%d%d", &n, &q) != EOF) {
		memset(T, 0, sizeof(T));
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		build(1, 1, n);
		while (q--) {
			scanf("%d%d", &x, &y);
			printf("%d\n", query1(1, 1, n, x, y) - query2(1, 1, n, x, y));
		}
	}
	return 0;
}
