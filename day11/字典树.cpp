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
const int maxn = 1e5 + 5;
int trie[maxn][26], tot ;
int flag[maxn];int sum[maxn];//判断最后是否是字母
char ss[maxn];
void insert(char *str)
{
	int len = strlen(str); int rt= 0;//len代表该字符串的长度，rt根节点的标号为0

	for (int i = 0; i < len; i++) {//扫描每个字符
		int id = str[i] - 'a';//给出每个字符的id a的标号为0
		if (!trie[rt][id]) trie[rt][id] = ++tot;//如果没有该节点没有数据，给上排序后的标号，顺序
	   sum[trie[rt][id]]++;	//标号更新
    rt = trie[rt][id];//该标号前缀的
	}
	flag[rt] = 1;//最后记录这个结尾后面是字母
}

int  query(char *str)
{
	int len = strlen(str), rt = 0;

	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (!trie[rt][i]) return 0;//如果找到跟节点则返回
    rt=trie[rt][id];

	}
	return sum[rt];
}
int main()
{
	//FAST_IO;6
	tot=0;
	memset(sum, 0, sizeof(sum));
	while (gets(ss)) {
		if (ss[0] == '\0') break;
		insert(ss);
	}
	while (gets(ss)) {
		cout << query(ss) << endl;
	}
	return 0;
}
