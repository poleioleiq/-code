#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <cctype>
#define maxx 0x3f3f3f3f
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
using namespace std;
const int maxn = 1e2 + 5;
int dp[maxn][maxn];
int sum[maxn]; int stone[maxn];
int main()
{
	FAST_IO;
	int n; cin >> n;
	memset(dp, maxx, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++) {
    cin>>stone[i];
		sum[i] = sum[i - 1] + stone[i];
		dp[i][i] = 0;
	}
	for (int len = 1; len <= n; len++) {//枚举每个长度
		for (int j = 1; j + len <= n + 1; j++) {////枚举起点，因为区间长度减去区间的len要大于0，所以是区间的起点
			int ends = j + len - 1;//终点
			for (int i = j; i < ends; i++) {//令i=j是从起点到终点开始遍历
				dp[j][ends] = min(dp[j][ends], dp[j][i] + dp[i + 1][ends] + sum[ends] - sum[j - 1]);
			}

		}
	}
	cout << dp[1][n]<<endl;;
	return 0;
}
