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
const int maxn = 1e5;

ll a[maxn];
struct tree {
	int l;
	int r;
	ll sum;
	ll lazy;
} t[maxn << 2];

void pushup(int rt)
{
	t[rt].sum = (t[rt << 1].sum + t[rt << 1 | 1].sum);
}

void pushdown(int rt)
{
	if (t[rt].lazy) {
		t[rt << 1].sum += (t[rt << 1].r - t[rt << 1].l + 1) * t[rt].lazy;//长度乘lazy
		t[rt << 1 | 1].sum += (t[rt << 1 | 1].r - t[rt << 1 | 1].l + 1) * t[rt].lazy;
		t[rt << 1].lazy += t[rt].lazy;
		t[rt << 1 | 1].lazy += t[rt ].lazy;
		t[rt].lazy = 0;//传一遍就行
	}

}

void build(int l, int r, int rt)
{
	t[rt].l = l;
	t[rt].r = r;
	t[rt].sum = 0;
	if (l == r) {
		t[rt].sum = a[l];
		return;
	}else{
		int m = (l + r) >> 1;
		build(lson);
		build(rson);
		pushup(rt);
	}
	return;
}

void update(int v, int l, int r, int rt)
{
	if (t[rt].l >= l && t[rt].r <= r) {
		t[rt].sum += 1LL * (r - l + 1) * v;//因为是区间更新某个值，所以是区间的长度乘lval；
		t[rt].lazy += v;
		return;
	}else {
		int m = (t[rt].l + t[rt].r) >> 1;
		pushdown(rt);
		if (r <= m) update(v, l, r, rt << 1);
		else if (l > m) update(v, l, r, rt << 1 | 1);
		else update(v, lson), update(v, rson);
		pushup(rt);
	}
	return;

}


ll  query(int l, int r, int rt)
{
	if (t[rt].l >= l && t[rt].r <= r) {
		return t[rt].sum;
	}
	pushdown(rt);
	int m = (t[rt].l + t[rt].r) >> 1;
	if (r <= m) return query(l,r,rt<<1);
	else if (l > m) return query(l,r,rt<<1|1);
	else return query(lson)+query(rson);
}

int main()
{
	char ch[10];
	int n, q;
	int l, r, v;
	int i;

	scanf("%d%d", &n, &q );
	for (i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	build(1, n, 1);
	while (q--) {
		scanf("%s", ch);
		if (ch[0] == '0') {
			scanf("%d%d", &l, &r );
			printf("%lld\n", query(l, r, 1));
		}else {
			scanf("%d%d%d", &l, &r, &v);
			update(v, l, r, 1);
		}
	}
	return 0;

}
