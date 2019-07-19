#include <bits/stdc++.h>

using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

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
	if (p <= m) Updata(p, v, lson);
	else Updata(p, v, rson);
	PushUP(rt);
}

int Query(int L, int R, int l, int r, int rt)
{
	if (L <= l && r <= R) return T[rt];
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret = max(ret, Query(L, R, lson));
	if (R > m) ret = max(ret, Query(L, R, rson));
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
