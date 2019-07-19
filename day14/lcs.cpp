#include <bits/stdc++.h>
using namespace  std;
const int maxn = 1e4 + 5;
int dp[maxn][maxn];
char s1[maxn], s2[maxn];
int len1, len2;
int main()
{
	while (cin >> s1 >> s2) {
		memset(dp, 0, sizeof(dp));
		len1 = strlen(s1);
		len2 = strlen(s2);
		for (int i = 0; i < len1; i++)for (int j = 0; j < len2; j++){
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}


		cout << dp[len1][len2] << endl;

	}
	return 0;


}
