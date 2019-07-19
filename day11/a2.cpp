
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
int  minpre(char s[])
{
	int m = strlen(s);

	memcpy(s + m, s, m * sizeof(char));
	int i = 0, j = 1;//i表示从i往后是有可能的，j表示下一个试探的位置
	while (j < m && i < m) {
		int k;
		for (k = 0; s[i + k] == s[j + k] && k < m; k++)
			if (k == m ) return min(i, j);          //如果相等了，那最小的就是答案
		if (s[i + k] > s[j + k]) i = i + k + 1;         //i到i+k开始的都不可能
		else (j = j + k + 1);                           //同上
		if (i == j) j++;                                //刚好相等，重新比较

	}
	if (i < m) return i;
	else return j;
}

int main()
{
	char s[20005];
	int n;

	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		printf("%d\n", minpre(s) + 1);
	}
}
