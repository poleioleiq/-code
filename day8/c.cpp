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
const int maxn = 1e2 + 5;
int m;
int vis[maxn], g[maxn][maxn], nxt[maxn];
int a[maxn], b[maxn];
bool find(int u)
{
	for (int i = 1; i <= m; i++) {
		if (!vis[i] && g[u][i] && a[i]) {
			vis[i] = 1;
			if (!nxt[i] || find(nxt[i])) {
				nxt[i] = u;
				return true;

			}
		}
	}
	return false;
}
bool work()
{

	for (int i = 1; i <= m; i++) {
		memset(vis, 0, sizeof(vis));
		if ((a[i] == 0 || b[i] == 0) && !find(i)) return false;
	}
	return true;
}
int main()
{
	FAST_IO;
	int t;
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof(vis));
		memset(g, 0, sizeof(g));
		memset(nxt, 0, sizeof(nxt));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> a[i];//是否在校1在校0不在校
		}
		for (int i = 1; i <= m; i++) {
			cin >> b[i];//是否回家，1回家0不回家
			if (a[i] == 0) b[i] = 1;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> g[i][j];
				//特判第自己和自己认识表示为 1
			}
			if (a[i]) g[i][i] = 1;//自己和自己链接！！！！！！！！！！！！！！！！
		}

		if (work()) cout << "^_^" << endl;
		else cout << "T_T" << endl;
	}

	return 0;
}
