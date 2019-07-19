#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;
const int maxn = 4e5 + 5;       //这个地方个人比较习惯设成4e几，因为这是个树，但应该都一样
int ary[maxn];                  //存储每一个工兵营的人数

struct node {
	int l, r, val;
} p[maxn];

//这个函数算是比较重要的，因为他把子节点的信息汇总到了父节点上，
//随着题目的改变这个函数也是需要作出相应改变的，并且有的时候要想全面。
void pushup(int cur)
{
	//父节点是两个子节点的和，一直往上传值，就能使根节点是所有人的个数
	p[cur].val = p[2 * cur].val + p[2 * cur + 1].val;
}

void build(int l, int r, int cur)
{
	int m = (l + r) / 2;

	p[cur].val = 0; //这个地方并没什么用，因为后面到了叶节点就会赋值了，但是有的时候，建树的初始值很重要
	p[cur].l = l;   p[cur].r = r;
	//如果到达叶节点就把人数赋给该节点
	if (l == r) {
		p[cur].val = ary[l];
		return;
	}
	//如果不是叶节点，就一直递归找左右孩子，然后知道找到叶节点进行传值
	build(l, m, 2 * cur);
	build(m + 1, r, 2 * cur + 1);
	//将子节点的人数进行汇总，给父节点
	pushup(cur);
}

//单点值的更改，找指定的叶节点，跟上面建树时候代码差不多，一直在找叶节点，然后对值做出相应更改
void update(int tar, int val, int cur)//tar是目标位置，即数组的下标，第几个工兵营，
{
	int l = p[cur].l, r = p[cur].r;

	if (l == r) {
		p[cur].val = p[cur].val + val;
		return;
	}
	int m = (l + r) / 2;
	if (tar <= m) update(tar, val, 2 * cur);
	else update(tar, val, 2 * cur + 1);
	pushup(cur);
}

//查询区间值
int query(int ql, int qr, int cur)
{
	int l = p[cur].l, r = p[cur].r;

	//如果一个树的节点所在的区间能够被所求区间完全包含（包括等于），那么就直接返回该区间值
	//我在学线段树的时候，看到这里总会担心，他这样的话返回了区间值，可是这个区间比所求区间可能小啊
	//	//的情况就是一直找到叶节点后来发现担心有点多余了，因为，他还有兄弟节点，如果他所在区间不够的话，会再去找他的兄弟，最不好

	if (ql <= l && qr >= r) return p[cur].val;
	int m = (l + r) / 2, res = 0;
	//如果不能完全包含，就去找他的左右孩子
	if (ql <= m) res += query(ql, qr, 2 * cur);
	if (qr > m) res += query(ql, qr, 2 * cur + 1);
	return res;
}

int main()
{
	int t, n;

	scanf("%d", &t);
	for (int test = 1; test <= t; test++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &ary[i]);
		build(1, n, 1);
		getchar();
		map<string, int> mp;
		mp["Query"] = 1;
		mp["Add"] = 2;
		mp["Sub"] = 3;
		mp["End"] = 4;
		int first = 1;
		while (1) {
			string str;
			cin >> str;
			if (first) printf("Case %d:\n", test), first = 0;
			if (mp[str] == 1) {
				int ql, qr;
				scanf("%d%d", &ql, &qr);
				printf("%d\n", query(ql, qr, 1));
			}else if (mp[str] == 2) {
				int c, m;
				scanf("%d%d", &c, &m);
				update(c, m, 1);
			}else if (mp[str] == 3) {
				int c, m;
				scanf("%d%d", &c, &m);
				update(c, -m, 1); //减去的话，就是加了个负数
			}else break;
		}
	}
	return 0;
}
