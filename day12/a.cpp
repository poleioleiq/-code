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
#define maxx(a, b) a > b？a:b
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
using namespace std;
const int maxn = 2e5 + 5;
int p[maxn];
char str[maxn << 1], s[maxn];
int id;
int len1, len2;
int ans;
void init()
{
	len1 = strlen(s);
	str[0] = '$';
	str[1] = '#';
	for (int i = 0; i < len1; i++) {
		str[i * 2 + 2] = s[i];
		str[i * 2 + 3] = '#';
	}
	len2 = len1 * 2 + 2;
	str[len2] = '*';//结束符号要求不一样，不然样例aaaa会返回数组大小

}
void  manacher()
{
	int id = 0, mx = 0;

	for (int i = 1; i < len2; i++) {
		if (mx > i) p[i] = min(p[id * 2 - i], mx - i);  //不确定是否超出取小的p[i]是该回文串的长度
		else p[i] = 1;                                  //如果超出了，就开始暴力
		for (; str[i - p[i]] == str[i + p[i]]; p[i]++);
		if (p[i ] + i > mx) {
			mx = p[i] + i;
			id = i;//更新
		}
	}
}

int main()
{
  FAST_IO;
	while (cin>>s) {
		len1 = strlen(s );
		init();
		manacher();
		ans = 0;
		for (int i = 0; i < len2; i++) {
			ans = max(ans, p[i]);
		}
		cout << ans - 1 << endl;
	}
  return 0;
}
