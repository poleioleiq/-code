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
void prime()
{
	int mins, next;

	memset(mst, 0, sizeof(mst));            //最小生成树初始化
	for (int i = 1; i <= m; i++) {
		lst[i] = path[1][i];            //初始化lst记录1村到每一个i村的花费，例如一村联通1，2，3 即记录11，12，13的花费
	}
	mst[1] = 1;                             //从1村开始构造最小生成树自己本身先入集合
	for (int i = 1; i < m; i++) {
		mins = maxx;
		for (int j = 1; j <= m; j++) {
			if (!mst[j] && mins > lst[j]) {         //及不在mst集合中且存在到j村的路
				mins = lst[j];                  //记录到j村的最小花费
				next = j;                       //从j村开始构建最小生成树
			}
		}
		if (mins == maxx) {             //存在某村没有修路安排，则肯定无法连通所有村
			cout << "?" << endl;    //直接输出，出函数
			return;
		}
		mst[next] = 1;                                          //next成为为最小生成树
		ans += mins;                                            //成本累加
		for (int j = 1; j <= m; j++) {
			if (!mst[j] && lst[j] > path[next][j]) {        //不是最小生成树且next村到j村成本小于(初始的)1村到j村成本
				lst[j] = path[next][j];                 //到j村成本更新
			}
		}
	}
	cout << ans << endl;    //输出所有连通成本
}
int main()
{
	FAST_IO;
	while (cin >> n >> m) {
		if (n == 0) {
			break;
		}
		memset(path, maxx, sizeof(path));
		while (n--) {
			cin >> p1 >> p2 >> cost;
			path[p1][p2] = path[p2][p1] = cost;
		}
		ans = 0;                                        //ans统计成本花费
		prime();                                        //prim算法走起
	}

	return 0;
}
