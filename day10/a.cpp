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

int  p[maxn], s[maxn];
int p_len, s_len;
int nxt[maxn];
int x, y;

void getnxt()
{
	int i = 0; int j = -1;
	nxt[0] = -1;
//	int p_len = strlen(p);
	while (i < y) {
		if (j == -1 || p[i] == p[j]) {
			i++;
			j++;
			nxt[i] = j;
		}else{
			j = nxt[j];
		}
	}
}
int kmp()
{
	getnxt();
	int i = 0, j = 0;
	while (i < x) {
		if (j == -1 || p[j] == s[i]) {
			i++;
			j++;
		}else{
			j = nxt[j];
		}if (j == y) {
			return i;//匹配完的下标
		}
	}
  return -1;
}
int main()
{
	int n;
  FAST_IO;
//	p_len = strlen(p);
//	s_len = strlen(s);
	cin >> n;

	while (n--) {
		cin >> x >> y;
		for (int i = 0; i < x; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < y; i++) {
			cin >> p[i];
		}
    if(kmp()==-1)cout<<"-1"<<endl;
		else cout << kmp()-y+1 << endl;
	}
	return 0;
}
