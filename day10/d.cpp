#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <stack>
#define maxx 0x3f3f3f3f
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
using namespace std;
const int maxn = 1e5 + 5;

int p_len, s_len;
char p[maxn];
int nxt[maxn];


void getnxt()
{
	int i = 0, j = -1;

	p_len = strlen(p);
	nxt[0] = -1;
	while (i < p_len) {
		if (j == -1 || p[j] == p[i]) {
			i++;
			j++;
			nxt[i] = j;
		}else j = nxt[j];
	}
}
int main()
{
	FAST_IO;
	int n;;
	cin >> n;
	while (n--) {
		cin >> p; p_len = strlen(p); getnxt();
		int len = p_len - nxt[p_len];

		if (nxt[p_len] == 0) {
			cout << len << endl;
			continue;
		}
		if (p_len % len == 0) cout << '0' << endl;
		else
			cout << len - (p_len % len) << endl;

	}
	return 0;
}
