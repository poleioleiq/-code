#include <iostream>
#define ll long long

using namespace std;
const int maxn = 1e5 + 5;
ll n, m;//n为点数，m为边数
int main()//求独点额数量
{
	cin >> n >> m;
	ll ans = max(0ll, n - 2 * m), ans1 = 0, ans2 = 0;
	if (m <= 1) {
		cout << ans << " " << ans << endl;
		return 0;//边的数量小于1的时候，每个边可以包含两个点，z最大值和最小值是一样的
	}
	for (int i = 2; i <= n; i++) {
		ans1 += i - 1;
		if (ans1 >= m) {
			ans2 = n - i;//算出最大值，饱和状态ans2;
			break;
		}
	}
	cout << ans << " " << ans2 << endl;
	return 0;
}
