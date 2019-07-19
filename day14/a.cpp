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
ll s[maxn], p[maxn];
int dp[maxn];
int main()
{
	FAST_IO;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> s[i];
		int m; cin >> m;
		for (int i = 0; i < m; i++) cin >> p[i];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			int mxx = 0;
			for (int j = 0; j < m; j++) {
				if (s[i] > p[j] && dp[j] > mxx) {
					mxx = dp[j];
				}
				if (s[i] == p[j]) {
					dp[j] = mxx + 1;
				}
			}

		}
		int mxx = 0;
		for (int i = 0; i < n; i++) {
			if (dp[i] > mxx)
				mxx = dp[i];
		}
		cout << mxx << endl;
		if (t) cout << endl;
	}
	return 0;
}
