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
int lst[maxn];  //
int mst[maxn];  //mst集合
int path[maxn][maxn];
int m, n, p1, p2, ans;
void prime()
{
	int mins, next;

	memset(mst, 0, sizeof(mst));
	for (int i = 1; i <= m; i++) {
		lst[i] = path[1][i];//chushihuahuafei
	}
	for (int i = 1; i < m; i++) {
		mins = maxx;//m-1geshengyucunzi
		for (int j = 1; j <= m; j++) {
			if (!mst[j] && mins > lst[j]) {
				mins = lst[j];
				next = j;//二层循环完毕，从j村开始构建最小生成树//扫出贪心的路径
			}
		}
		if (mins == maxx) {
			cout << "?" << endl;
			return;
		}
		mst[next] = 1;
		ans += mins;
		for (int j = 1; j <= m; j++) {
			if (!mst[j] && lst[j] > path[next][j]) {
				lst[j] = path[next][j];
			}
		}
	}
	cout << ans << endl;
}
int main()
{
	FAST_IO;
	while (cin >> n >> m) {
		if (n == 0) break;
	}
}
