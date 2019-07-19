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
#define minn(a, b) a < b ? a : b
#define maxxx(a, b) a > b？a:b
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
using namespace std;
const int maxn = 2e7 + 5;
char str[maxn<<1], s[maxn];
int p[maxn], id, ans, len1, len2;

void manacher()
{
	int mx = 0, id = 0;

	for (int i = 1; i < len2; i++) {
		if (mx>i) p[i] = min(p[id*2 - i ], mx - i);
		else p[i] = 1;
		for (; str[p[i] + i] == str[i - p[i]]; p[i]++);
		if (p[i] + i > mx) {
      mx = p[i] + i;
		    id = i;
	}
}
}
void init()
{
	len1 = strlen(s);
	str[0] = '@';
	str[1] = '#';
	for (int i = 0; i < len1; i++) {
		str[i * 2 + 2] = s[i];
		str[i * 2 + 3] = '#';
	}
	len2 = len1 * 2 + 2;
	str[len2] = '^';
}
int  main()
{
  FAST_IO;
	while (cin >> s) {
		len1 = strlen(s);
    init();
		manacher();
		ans = 0;
    for (int i = 0; i < len2; i++) {
		ans = max(p[i], ans);
	 }
  cout << ans - 1 << endl;
	}

	return 0;
}
