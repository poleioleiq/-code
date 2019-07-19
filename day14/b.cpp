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
const int maxn=2e5+5;
int n, a[maxn];
int main()
{
	while (scanf("%d", &n) != EOF) {
		int sum = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);//
		bool flag = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] >= a[i - 1] && a[i] >= a[i + 1] && !flag) {
				sum += a[i];//加上是大的并且是奇数次
				flag = 1;
			}
			if (a[i] <= a[i - 1] && a[i] <= a[i + 1] && flag) {
				sum -= a[i];
				flag = 0;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
