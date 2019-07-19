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
const int maxn = 1e3 + 5;
int vis[maxn], nxt[maxn], g[maxn][maxn];

int m,n;
bool find(int u)
{
	for (int i = 1; i <= m; i++) {
		if (!vis[i] && g[u][i]) {
			vis[i] = 1;
			if (!nxt[i] || find(nxt[i])) {
				nxt[i] = u;
				return true;
			}
		}

	}
	return false;
}

int main()
{
	int k;
	int x, y;
	int sum;

	while (cin >> k, k != 0) {
		/* code */ cin >> m >> m; sum = 0;
		memset(vis, 0, sizeof(vis));
		memset(nxt, 0, sizeof(nxt));
		memset(g, 0, sizeof(g));
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			g[x][y] = 1;
		}
		for (int i = 1; i <= m; i++) {
			memset(vis, 0, sizeof(vis));
			if (find(i)) sum++;
		}
		cout << sum << endl;
	}
	return 0;
}
