
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 30;
const int inf = 0x3f3f3f3f;
int road[maxn][maxn], dis[maxn];
bool vis[maxn];
int n;
void prim()
{
	int mi, v;

	for (int i = 0; i < n; i++) {
		dis[i] = road[0][i];
		vis[i] = false;
	}
	for (int i = 1; i <= n; i++) {//包括第一个点在内，一共要纳入n个点
		mi = inf;
		for (int j = 0; j < n; j++) {//每次找出未纳入顶点集与已知顶点集构成的权值最小的一条边
			if (!vis[j] && mi > dis[j]) {
				v = j;
				mi = dis[j];
			}
		}
		vis[v] = true;//把该顶点纳入已知集合
		for (int j = 0; j < n; j++) {//更新与未纳入集合中的顶点的边的最小权值
			if (!vis[j] && dis[j] > road[v][j])
				dis[j] = road[v][j];
		}
	}
	for (int i = 1; i < n; i++)
		dis[0] += dis[i];
	cout << dis[0] << endl;
}
int main()
{
	int m, w;
	char s[5], en[5];

	while (cin >> n, n) {
		memset(road, 63, sizeof(road));
		for (int i = 0; i < n; i++)
			road[i][i] = 0;
		for (int i = 1; i < n; i++) {
			scanf("%s%d", s, &m);
			for (int j = 0; j < m; j++) {
				scanf("%s%d", en, &w);
				road[s[0] - 'A'][en[0] - 'A'] = road[en[0] - 'A'][s[0] - 'A'] = w;
			}
		}
		prim();
	}
	return 0;
}
