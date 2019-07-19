#include <iostream>//panduanerfentu yinwei若是存在奇数环
//一个个入队列，
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e6 + 5;
vector<int>g[maxn];
int n, m, s, vis[maxn];
bool bfs()
{
	int blag = 0;
	queue<int>q;

	memset(vis, 0, sizeof(vis));
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];//与g[i]有边的点
			if (vis[v] == 0) {
				vis[v] = -vis[u];
				q.push(v);
			}else if (vis[v] == vis[u])
				blag = 1;
		}
	}
	for (int i = 0; i < n; i++)
		if (vis[i] == 0)
			return false;
	return blag;
}

int main()
{
	int t, tt = 1, u, v;

	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &s);
		for (int i = 0; i < n; i++)
			g[i].clear();
		while (m--) {
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		printf("Case %d: %s\n", tt++, bfs() ? "YES" : "NO");
	}
}
