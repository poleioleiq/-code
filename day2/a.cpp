#include <bits/stdc++.h>
using namespace std;
int aa[10005];
int bb[10005];
void query(int a, int b, int n, int flag)
{
	if (n == 1) {
		printf("%d ", aa[a]);
		return;
	}else if (n <= 0)
		return;
	int i;                                  //aa[]qianxu,bb[]zhongxu
	for (i = 0; aa[a] != bb[b + i]; i++);   //扫描根节点，然后左右划分,格式注意flag，递归开始后就flag为0
	query(a + 1, b, i, 0);
	query(a + i + 1, b + i + 1, n - i - 1, 0);
	if (flag == 1) printf("%d", aa[a]);
	else printf("%d ", aa[a]);
}
int main()
{
	int n, i;

	while (~scanf("%d", &n)) {
		for (i = 1; i <= n; i++) cin >> aa[i];
		for (i = 1; i <= n; i++) cin >> bb[i];
		query(1, 1, n, 1);
		cout << endl;
	}
	return 0;
}
