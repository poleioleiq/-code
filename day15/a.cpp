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
const int maxn = 1e3 + 5;
int dp[10][10];
int d[10];

void init()
{
	dp[0][0] = 1;
	for (int i = 1; i <= 7; i++)//位数
		for (int j = 0; j <= 9; j++)//后置位
			for (int k = 0; k <= 9; k++)
				if (j != 4 && !(j == 6 && k == 2))
					dp[i][j] += dp[i - 1][k];

}
int solve(int n)
{
	int ans = 0;
	int len = 0;

	while (n) {
		len++;
		d[len] = n % 10;
		n /= 10;
	}
	d[len + 1] = 0;
	for (int i = len; i >= 1; i--) {
		for (int j = 0; j < d[i]; j++) {
			if (d[i + 1] != 6 || j != 2)
				ans += dp[i][j];
		}
		if (d[i+1] == 4 || (d[i + 1] == 6 && d[i] == 2))
			break;
	}
	return ans;
}

int main()
{
	FAST_IO;
	int n, m;
	init();
	while (scanf("%d%d",&n,&m)==2) {
    if(n==0&&m==0)break;
		cout << solve(m + 1) - solve(n) << endl;
	}
	return 0;
}
