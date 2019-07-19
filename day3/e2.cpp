#include <bits/stdc++.h>
#define N 1010
using namespace std;
int bin[N];
int n, m, x, y;
void init()
{
	for (int i = 0; i <= n; i++)
		bin[i] = i;
}
int findx(int x)
{
	while (x != bin[x])
		x = bin[x];
	return x;
}
int main()
{
//freopen("C:\\Users\\acer\\Desktop\\in.txt","r",stdin);
	while (scanf("%d", &n) != EOF && n) {
		scanf("%d", &m);
		int cur = 0;
		init();
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			int fx = findx(x);
			int fy = findx(y);
			if (fx != fy)
				bin[fy] = fx;
		}
		for (int i = 1; i <= n; i++) {
			if (bin[i] == i)
				cur++;
		}
		printf("%d\n", cur - 1);
	}
	return 0;
}
