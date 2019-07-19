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
const int maxn = 1e4 + 5;
int ran[maxn];
int pre[maxn];

int n, m;

void init()
{
	for (int i = 1; i <= n; i++) {
		pre[i] = i;
		ran[i] = 1;
	}
}

int find(int x)
{
	if (x == pre[x]) return x;
	return pre[x] = find(pre[x]);
}

void join(int x, int y)
{
	int fx = find(x);
	int fy = find(y);

	if (fx == fy) return;
	if (ran[x] < ran[y]) pre[fx] = fy;
	else {
		pre[fy] = fx;
		if (ran[fx] == ran[fy]) ran[fx]++;
	}
}

int main()
{
	FAST_IO;
	while (cin >> n, n) {
		cin >> m;
		init();
		int a, b;
		while (m--) {
			cin >> a >> b;
			join(a, b);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (pre[i] == i) ans++;
		}
		cout << ans - 1 << endl;
	}
	return 0;
}
