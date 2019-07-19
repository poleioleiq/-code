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


int p_len, s_len;
char p[maxn], s[maxn];
int nxt[maxn];


void getnxt()
{

	int i = 0;
	int j = -1;
  int p_len = strlen(p);
	nxt[0] = -1;
	while (i < p_len) {
		if (  j == -1||p[i] == p[j]) {
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
	int i = 0; int j = 0;
	int ans = 0;
  int p_len = strlen(p);
	int s_len = strlen(s);

	while (i < s_len) {
		if (j == -1||p[j] == s[i]  ) {
			i++;
			j++;
      if (j == p_len) {
        //cout<<"!!!"<<endl;
  			ans++;
        j = nxt[j];
		  }
		}else{
			j = nxt[j];
		}

	}
	return ans;
}

int main()
{
  FAST_IO;
	int n;
	cin >> n;
	while (n--) {
		cin >> p;
		cin >> s;
		cout << kmp() << endl;
	}
	return 0;
}
