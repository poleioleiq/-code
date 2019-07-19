#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#define maxx 0x3f3f3f3f
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
using namespace std;
const int maxn = 2e6 + 5;
int tree[maxn][30];
int flag[maxn];
int sum[maxn];
int tot;
void insert(char *str)
{
	int len = strlen(str);
	int rt = 0;

	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (!tree[rt][id])
			tree[rt][id] = ++tot;
		sum[tree[rt][id]]++;
		rt = tree[rt][id];
	}
	flag[rt] = 1;
}
int find(char *str)
{
	int len = strlen(str);
	int rt = 0;

	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (!tree[rt][id])
			return 0;
		rt = tree[rt][id];
	}
	return sum[rt];
}
char ss[maxn];
int main()
{
	FAST_IO;
	tot = 0;
	memset(sum, 0, sizeof(sum));
	while (gets(ss)) {
		if (ss[0] == '\0')
			break;
		insert(ss);
	}
	while (gets(ss)) {
		cout<<find(ss)<<endl;
	}
	return 0;
}
