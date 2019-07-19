#include <bits/stdc++.h>//奇数偶数染色，，ans1*ans2-(n-1)即为答案
#define ll long long
using namespace std;
const int maxn = 100005;
vector<int >v[maxn];
int vis[maxn];
ll ans1, ans2;
void dfs(int a, int ans3)
{
	for (int i = 0; i < v[a].size(); i++) {
		if (!vis[v[a][i]]) {
			vis[v[a][i]] = 1;//没访问过，就标记
			if (ans3 % 2 == 1) ans1++;
			else ans2++;
			dfs(v[a][i], ans3 + 1);//递归下一个系欸点
		}
	}
}
int main()
{
	int n, a, b;

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ans2 = 0; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ans1 = 1;
	vis[1] = 1;
	dfs(1, 0);
	cout << ans1 * ans2 - (n - 1) << endl;
	return 0;
}
