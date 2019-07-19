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
int n, m;
int dis[110][110];
void floyd()
{
	for (int t = 0; t < n; t++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					dis[i][j] = 0;
					continue;
				}
				dis[i][j] = min(dis[i][j], dis[i][t] + dis[t][j]);
			}

		}
	}
}

int main()
{
	FAST_IO;
	cin >> n >> m;
	memset(dis, 0x0f, sizeof(dis));
	int v, u, d;
	for (int i = 0; i < m; i++) {
		cin >> v >> u >> d;
		v--;
		u--;
		dis[v][u] = min(dis[v][u], d);
		dis[u][v] = min(dis[u][v], d);

	}
	floyd();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
