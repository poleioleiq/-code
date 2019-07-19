#include <bits/stdc++.h>//先读图，indegree记录入读
//一开始的操作时如图，后来如果联通，indgree[j]就++;
//找到入度为零的点，indgree{i}==-1;并且indegree[j]--;
using namespace std;
const int maxn = 5e2 + 5;
int g[maxn][maxn];
int indgree[maxn];
int ans[maxn];
void mem()
{
	memset(g, 0, sizeof(g));
	memset(indgree, 0, sizeof(indgree));
	memset(ans, 0, sizeof(ans));
}
void topo()
{
  int n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (g[i][j]) indgree[j]++;
	for (int i = 1; i <= n; i++) {
		int k = 1;
		while (indgree[k] != 0) k++;
		ans[i] = k;//记录k点
		indgree[k] = -1;
		for (int j = 1; j <= n; j++) if (g[k][j]) indgree[j]--;
	}
}
int main()
{
	int n, m;

	while (~scanf("%d%d", &n, &m)) {
		mem();
		int x, y;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			g[x][y] = 1;
		}
		topo();
		for (int i = 1; i < n; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[n]);//jizhu  pe技巧
	}
	return 0;
}
