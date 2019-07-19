#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <cctype>
#include <map>
#define maxx 0x3f3f3f3f
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
const int maxn = 2e5;
int a[maxn];
int x,y;
struct tree {
	int ma, mi;

} t[maxn << 2];

 inline void pushup(int rt)
{
	t[rt].ma = max(t[rt << 1].ma, t[rt << 1 | 1].ma);
	t[rt].mi = min(t[rt << 1].mi, t[rt << 1 | 1].mi);
}

 inline void build(int l, int r, int rt)
{
	if (l == r) {
		t[rt].mi = a[l];
		t[rt].ma = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}
int query(int l, int r, int rt, int x, int y)
{
	if (x <= l && r <= y) return t[rt].ma;
	int m = (l + r) >> 1;
	if (y <= m) return query(lson, x, y);
	else if (x > m) return query(rson, x, y);
	else return max(query(rt << 1, 1, m, x, m), query(rt << 1 | 1, m + 1, r, m + 1, y));
}
int query2(int l, int r, int rt, int x, int y)
{
	if (x <= l && r <= y) return t[rt].mi;
	int m = (l + r) >> 1;
	if (y <= m) return query2(lson, x, y);
	else if (x > m) return query2(rson, x, y);
	else return min(query2(rt << 1, 1, m, x, m), query2(rt << 1 | 1, m + 1, r, m + 1, y));
}
int main()
{
	int n, q;
	int x, y;

	while (scanf("%d%d", &n, &q) != EOF) {
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		build(1, n, 1);
		while (n--) {
			scanf("%d%d", &x, &y);
			printf("%d\n", query(1, n, 1, x, y) - query2(1, n, 1, x, y));
		}
	}
	return 0;
}
