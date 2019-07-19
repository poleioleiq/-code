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
int  m;

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
  FAST_IO;
	int t;
	cin >> t;
	while (t--) {
		memset(nxt, 0, sizeof(nxt));
		memset(vis, 0, sizeof(0));
		memset(g, 0, sizeof(0));


		cin >> m;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> g[i][j];//代表很坐标与数座标有一条连线；
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			memset(vis, 0, sizeof(vis));
			ans += find(i);
		}
		if (ans == m) cout << "Yes" << endl;
		else cout << "No" << endl;

	}
	return 0;
}
