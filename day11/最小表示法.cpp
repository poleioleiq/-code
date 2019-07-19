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
char p[maxn];

int getmin()
{
	int n = strlen(p);

	memcpy(p + n, p, n * sizeof(char));
	int i = 0, j = 1;
	while (i < n && j < n) {
		int k;
		for ( k = 0; p[i + k] == p[j + k] && k < n; k++) if (k == n) return min(i,j);
		if (p[i + k] > p[j + k]) i = i + k + 1;
		else j = (j + k + 1);
		if (i == j) j++;
	}
	if (i < n) return i;
	else return j;
}
int main()
{
	int n;
  FAST_IO;
	cin >> n;
	while (n--) {
		cin >> p;
		cout << getmin()+1 << endl;//下标位置加一
	}
	return 0;
}
