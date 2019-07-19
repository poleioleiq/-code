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
int g[maxn][maxn], vis[maxn], nxt[maxn];

int m, n;
bool find(int u)                        //给第u个男生匹配女生
{
	for (int i = 1; i <= n; i++) {  //扫描女生
//如果没有访问过这个点并且这个点是预先匹配过的
		if (!vis[i] && g[u][i]) {
			vis[i] = 1;
			//若该女生只有这个选择，或者本应和这个女生匹配的男生nxt[i]找到了另外的女生，那么nxt[i]就匹配这个男生u；
			if (!nxt[i] || find(nxt[i]))
				nxt[i] = u;
			return true;
		}
	}
	return false;
}
int main()
{
	FAST_IO;
	int k;
	int x, y, sum;
	while ((cin >> k ), k != 0) {
    cin>> m >> n;
		memset(nxt, 0, sizeof(nxt));
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			g[x][y] = 1;
		}
		sum = 0;
		for (int i = 1; i <= m; i++) {
			memset(vis, 0, sizeof(vis));
			if (find(i)) sum++;
		}
		cout << sum << endl;
	}
	return 0;

}
