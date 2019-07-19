#include<iostream>
using namespace std;
const int maxn = 2e4 + 5;
int f[maxn];
int main()
{
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> f[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int temp = 1;
		int t = f[i];
		while (t != -1) {
			t = f[t];
			temp++;
		}
		ans = max(temp, ans);
	}
	cout << ans << endl;
	return 0;
}
