#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#define inf (1 << 30)
#define maxx 0x3f3f3f3f
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

#pragma coMAXNent(linker, "/STACK:102400000,102400000")
using namespace std;
const int MAXN = 80010;
int n, m, num;
int head[MAXN], cnt;
int dis[MAXN];
int E[MAXN], R[MAXN];
struct edg {
	int w, u, v, next;
} ED[MAXN];
void add(int u, int v, int w)
{
	ED[cnt].u = u;
	ED[cnt].v = v;
	ED[cnt].w = w;
	ED[cnt].next = head[u];
	head[u] = cnt++;
}
void dfs(int u, int d, int last)
{
	if (R[u] == -1) R[u] = num;
	E[num++] = u;
	dis[u] = d;
	for (int i = head[u]; ~i; i = ED[i].next) {
		int v = ED[i].v;
		if (v == last) continue;
		dfs(v, d + ED[i].w, u);
		E[num++] = u;
	}
}
int dp[MAXN][17];
void rmq_init()
{
	int L = num;

	for (int i = 0; i < L; i++) dp[i][0] = E[i];
	for (int j = 1; (1 << j) <= num; j++) {
		for (int i = 0; (i + (1 << j)) <= num; i++)
			if (dis[dp[i][j - 1]] < dis[dp[i + (1 << (j - 1))][j - 1]]) dp[i][j] = dp[i][j - 1];
			else dp[i][j] = dp[i + (1 << (j - 1))][j - 1];
	}
}
int rmq(int L, int R)
{
	if (L > R) swap(L, R);
	int k = log(R - L + 1.0) / log(2.0);
	return min(dp[L][k], dp[R - (1 << k) + 1][k]);
}
int LCA(int u, int v)
{
	return rmq(R[u], R[v]);
}
int main()
{
	int T;

	scanf("%d", &T);
	while (T--) {
		cnt = 0;
		scanf("%d%d", &n, &m);
		memset(R, -1, sizeof(R));
		memset(head, -1, sizeof(head));
		for (int i = 0; i < n - 1; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		num = 0;
		dfs(1, 0, 0);
		rmq_init();
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			int l = LCA(u, v);
			printf("%d\n", dis[u] + dis[v] - 2 * dis[l]);
		}
	}
	return 0;
}
