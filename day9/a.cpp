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
int g[maxn][maxn];
int dp[maxn][maxn];
int n, m, d;
void floyd()
{
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}

int main()
{
	FAST_IO;
	int x, y, d;memset(dp, 1, sizeof(dp));
	while (cin >> n >> m) {

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) dp[i][j] = 0; //zihuan de ju li wei 1;
				else dp[i][j] = maxx;
			}
		}
		for (int i = 1; i <= n; i++) {
			cin >> x >> y >> d;
			if (d < dp[x][y]){
         dp[x][y] = d;
			   dp[y][x] = d;
      }

		}
		floyd();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cout << dp[i][j] << ' ';
		cout << endl;
	}
	return 0;

}
