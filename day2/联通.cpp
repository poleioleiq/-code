//二分图可以认为是两个点集合ab，ab,两个点集相互连接，ruoa =aa;b=bb;则最大条边的数量为aa*bb。若要求原二分图还能加多少条边，减去即可
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
vector<int>V[100100];
int vis[100100];
ll num0;
ll num1;
void dfs(int x, int step)
{
	for (int i = 0; i < V[x].size(); i++) {
		if (!vis[V[x][i]]) {
			vis[V[x][i]] = 1;
			if (step % 2 == 1) num0++;
			else num1++;
			dfs(V[x][i], step + 1);
		}
	}
}
int main()
{
	int n, a, b;

	scanf("%d", &n);
	for (int k = 0; k < n - 1; k++) {
		num1 = 0;
		scanf("%d%d", &a, &b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	num0 = 1;
	vis[1] = 1;
	dfs(1, 0);
	cout << num0 * num1 - (n - 1) << endl;
	return 0;
}
