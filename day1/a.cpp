#include <iostream>
#define fo(i, a, b) for (i = a; i <= b; i++)
#define fd(i, a, b) for (i = a; i >= b; i--)
#define N 300000
using namespace std;
int n, k, i, j, r, st, ed;
int f[N], a[N], pre[N], suc[N], res[N];
int main()
{
	cin >> n >> k;
	fo(i, 1, n){
		cin >> a[i];
		f[a[i]] = i;
		pre[i] = i - 1; //前置节点，左
		suc[i] = i + 1; //后继节点
	}
	r = 1;
	fd(i, n, 1)             //从
	if (f[i]) {             //寻找当前的最大值
		ed = f[i];
		fo(j, 1, k){    //向后找
			if (suc[ed] == n + 1) break;
			ed = suc[ed];
			f[a[ed]] = 0; res[ed] = r;
		}
		ed = suc[ed];

		st = f[i];
		fo(j, 1, k){//向前找
			if (pre[st] == 0) break;
			st = pre[st];
			f[a[st]] = 0; res[st] = r;
		}
		st = pre[st];

		suc[st] = ed; pre[ed] = st;//删除
		res[f[i]] = r; f[i] = 0;
		r = 3 - r;
	}
	fo(i, 1, n) cout << res[i]; cout << endl;
	return 0;
}
