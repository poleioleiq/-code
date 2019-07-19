#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
vector <int >g[maxn];

int v;
int color[maxn];



bool dfs(int v, int c)
{
	color [v] = c;
	for (int i = 0; i < g[v].size(); i++) {//把当前点相邻的点都扫一遍
		if (color[g[v][i]] == c) return false;//如果相邻的点都被染成同色了，则说名不是二分图
    //如果相邻点没有被染色，则搜索下一串相邻点，染成-色，看相邻点是否符合要求
		if (color[g[v][i]] == 0 && !dfs(g[v][i], -c)) {
			return false;

		}
	}
	return true;

}
void solve()
{
	for (int i = 0; i < v; i++) {//可能不为连通图，所以每个点都要dfs一遍
		if (color[i] == 0)
			if (!dfs(i, 1)){
        cout << "false" << endl;
        return;
      }
    }
  }
