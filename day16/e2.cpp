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
const int maxn = 1e5 + 10;
int n, q;
ll a[maxn];
struct tree {
	int l;
	int r;
	ll sum;
} t[maxn << 2];

void pushup(int rt)
{
	t[rt].sum = t[rt << 1].sum + t[rt << 1 | 1].sum;
}

void build(int rt, int l, int r)
{
	t[rt].l = l;
	t[rt].r = r;

	if (l == r) {
		t[rt].sum = a[l];
		return;
	}

	int mid = (l + r) >> 1;

	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
	return;
}

void update(int rt, int L, int R)
{
	if (t[rt].sum == t[rt].r - t[rt].l + 1) //因为长度为一就是区间的值
		return;
	if (t[rt].l == t[rt].r) {
		t[rt].sum = (ll)(sqrt(t[rt].sum));        //直接开方就行了
		return;
	}

	int mid = (t[rt].l + t[rt].r) >> 1;
	if (L <= mid) update(rt << 1, L, R);
	if (R >  mid) update(rt << 1 | 1, L, R);
	pushup(rt);
	return;
}
ll query(int rt, int L, int R)
{

	if (L <= t[rt].l && t[rt].r <= R) {
		return t[rt].sum;
	}

	int mid = (t[rt].l + t[rt].r) >> 1;
	ll ans = 0;
	if (L <= mid) ans += query(rt << 1, L, R);
	if (R >  mid) ans += query(rt << 1 | 1, L, R);
	return ans;
}

int main()
{
	int i = 0;

	while (scanf("%d", &n) != EOF) {
		printf("Case #%d:\n", ++i);
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &a[i]);

		build(1, 1, n);

		scanf("%d", &q);

		while (q--) {
			int t, l, r;
			scanf("%d%d%d", &t, &l, &r);
			if (l > r) swap(l, r);
			if (t)
				printf("%lld\n", query(1, l, r));
			else
				update(1, l, r);
		}
		printf("\n");
	}
	return 0;
}
