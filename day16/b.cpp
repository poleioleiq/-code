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
const int N = 200000 + 5;
int T[N << 2];

void PushUP(int rt)
{
	T[rt] = max(T[rt << 1], T[rt << 1 | 1]);
}

void Build(int l, int r, int rt)
{
	if (l == r) {
		scanf("%d", &T[rt]);
		return;
	}
	int m = (l + r) >> 1;
	Build(lson);
	Build(rson);
	PushUP(rt);
}

void Updata(int p, int v, int l, int r, int rt)
{
	if (l == r) {
		T[rt] = v;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) Updata(p, v, lson); //pos指数组的下标
	else Updata(p, v, rson);
	PushUP(rt);
}

int Query(int ql, int qr, int l, int r, int rt)
{
	if (ql <= l && r <= qr) return T[rt];
	int m = (l + r) >> 1;
	int ret = 0;
	if (ql <= m) ret = max(ret, Query(ql, qr, lson));
	if (qr > m) ret = max(ret, Query(ql, qr, rson));
	return ret;
}

int main()
{
	char ch[3];
	int n, m, a, b;

	while (scanf("%d %d", &n, &m) == 2) {
		Build(1, n, 1);
		for (int i = 1; i <= m; i++) {
			scanf("%s %d %d", ch, &a, &b);
			if (ch[0] == 'Q') printf("%d\n", Query(a, b, 1, n, 1));
			else Updata(a, b, 1, n, 1);
		}
	}
	return 0;
}
