#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int pre[maxn], nxt[maxn], res[maxn], a[maxn], f[maxn];
int n, k, i, j, r, st, ed;
int main()
{
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[a[i]] = i;
		pre[i] = i - 1;
		nxt[i] = i + 1;
	}
	int r = 1;
	for (int i = n; i >= 1; i-- ) {
		if (f[i]) {
			ed = f[i];
			for (int j = 1; j <= k; k++) {
				if (nxt[ed] == n + 1) break;
				ed = nxt[ed];
				f[a[ed]] = 0; res[ed] = r;
			}
			ed = nxt[ed];
			st = f[i];
			for (int j = 1; j <= k; j++) {
				if (pre[st] == 0) break;
				st = pre[st];
				f[a[st]] = 0; res[st] = r;
			}
			st = pre[st];
			nxt[st] = ed; pre[ed] = st;
			res[f[i]] = r; f[i] = 0;
			r = 3 - r;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i];
	}
	return 0;
}
