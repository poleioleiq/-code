#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <stack>
#define maxx 0x3f3f3f3f
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
using namespace std;
int vis[10001];
int nxt[10001];
int e[101][101];
int rn[10001], b[10001];
int ans = 0, n = 0;
bool dfs(int u)
{
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0 && rn[i] == 1 && e[u][i] == 1) {
			vis[i] = 1;
			if (nxt[i] == 0 || dfs(nxt[i]) == true) {
				nxt[i] = u;
				return true;
			}
		}
	}
	return false;
}
bool work()
{
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		if ((rn[i] == 0 || b[i] == 0) && (dfs(i) == false)) {
			return false;
		}
	}
	return true;
}
int main()
{
	int t = 0;

	scanf("%d", &t);
	while (t--) {
		ans = 0;
		memset(vis, 0, sizeof(vis));
		memset(nxt, 0, sizeof(nxt));
		memset(rn, 0, sizeof(rn));
		memset(b, 0, sizeof(b));
		memset(e, 0, sizeof(e));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &rn[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
			if (rn[i] == 0) {
				b[i] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &e[i][j]);
			}
			if (rn[i] == 1) {
				e[i][i] = 1;
			}
		}
		if (work() == true) {
			printf("^_^\n");
		}else {
			printf("T_T\n");
		}
	}
	return 0;
}
