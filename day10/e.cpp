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
const int maxn = 1e6 + 5;
int p_len;
char p[maxn];
int nxt[maxn];
void getnxt()
{
	int i = 0, j = -1;

	nxt[0] = -1;
	while (i < p_len) {
		if (j == -1 || p[i] == p[j]) {
			i++; j++;
			nxt[i] = j;
		}else j = nxt[j];
	}
}
int main()
{
	int n;

	while (cin >> n, n != 0) {
    memset(nxt,0,sizeof(nxt));
    memset(p,'0',sizeof(p));
    cin >> p;
    
		p_len = strlen(p);
		getnxt();
		int len = p_len - nxt[p_len];
		cout << "Test case #2" << endl;
		for (int i = 2; i <= p_len; i++) {
			if (nxt[i] != 0 && p_len % (len) == 0) {
				cout << i << " " << i / len << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
