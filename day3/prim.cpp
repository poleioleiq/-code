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
int p1, p2, cost, n, m, ans;
int path[maxn][maxn];   //记录从i到j村的花费
int lst[maxn];          //记录到j村的最小花费//1到不了i村则lst[i]=INT_MAX
int mst[maxn];          //构建最小生成树
void prim()
{
	int mins, next;

	memset(mst, 0, sizeof(mst));    //最小生成树初始化几点都为0；及为自己绷绳的节点
	for (int i = 1; i <= m; i++) {
		lst[i] = path[1][i];    //初始化lst记录到每个i村的花费

	}
	mst[1] = 1;
	for (int i = 1; i < m; i++) {   //还剩余m-1个节点
		mins = maxx;         //初始化路径长度为无线长；
		for (int j = 1; j <= m; j++) {
			if (!mst[j] && mins > lst[j]) {
				mins = lst[j];  //更新if到j点的距离//在当前节点
				next = j;       //开始构建j的最小生成树
			}
		}
		if (mins == maxx) {//若果该点不连通，就输出？；
			cout << "?" << endl;
			return;
		}
		mst[next] = 1;
		ans += mins;
		for (int j = 1; j <= m; j++) {
			if (!mst[j] && lst[j] > path[next][j]) {//及不在mst集合中，并且小于mins的值更新，并且更新next值，开始构建最小生成树
				lst[j] = path[next][j];
        next=j;
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
		memset(path,maxx, sizeof(path));
		while (n--) {
			cin >> p1 >> p2 >> cost;
			path[p1][p2] = path[p2][p1] = cost;
		}
		ans = 0;
		prim();
	}
	return 0;
}
