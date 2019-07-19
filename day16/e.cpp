// #include <iostream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <climits>
// #include <queue>
// #include <vector>
// #include <stack>
// #include <algorithm>
// #include <cctype>
// #include <map>
// #define maxx 0x3f3f3f3f
// #define ll long long
// #define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
// #define lson l, m, rt << 1
// #define rson m + 1, r, rt << 1 | 1
// using namespace std;
//
// const int maxn = 1e5 + 5;
// int a[maxn];
// struct tree {
// 	int l;
// 	int r;
// 	ll sum;
// 	ll lazy;
// } t[maxn << 2];
//
// inline void pushup(int rt)
// {
// 	t[rt].sum = t[rt << 1].sum + t[rt << 1 | 1].sum;
// }
//
// inline void pushdown(int rt)
// {
// 	if (t[rt].lazy) {
// 		t[rt << 1].sum += (t[rt << 1].l - t[rt << 1].r + 1) * t[rt].lazy;
// 		t[rt << 1 | 1].sum += (t[rt << 1 | 1].l - t[rt << 1 | 1].r + 1) * t[rt].lazy;
// 		t[rt << 1].lazy += t[rt].lazy;
// 		t[rt << 1 | 1].lazy += t[rt].lazy;
// 		t[rt].lazy = 0;
// 	}
// }
//
//
// void build(int l, int r, int rt)
// {
// 	t[rt].l == l; t[rt].r = r;
// 	if (l == r) {
// 		t[rt].sum = a[l];
// 		return;
// 	}
// 	int m = (l + r) >> 1;
// 	build(l, m, rt << 1);
// 	build(m + 1, r, rt << 1 | 1);
// 	pushup(rt);
// }
//
// inline void update(int l, int r, int rt)
// {
// 	if (t[rt].l >= l && t[rt].r <= r) {
// 		t[rt].sum += floor(sqrt(1LL * (l - r + 1))) ;
// 		t[rt].lazy +=
// 		return;
// 	}else{
// 		int m = (t[rt].l + t[rt].r) << 1;
// 		pushdown(rt);
// 		if (r <= m) return update(l, r, rt << 1, v);
// 		else if (l > m) return update(l, r, rt << 1 | 1, v);
// 		else return update(l, m, rt << 1, v), update(m + 1, r, rt << 1 | 1, v);
// 		pushup(rt);
// 	}
// 	return;
// }
//
// ll  query(int l, int r, int rt)
// {
// 	if (t[rt].l >= l && t[rt].r <= r) {
// 		return t[rt].sum;
// 	}
// 	pushdown(rt);
// 	int m = (t[rt].l + t[rt].r) >> 1;
// 	if (r <= m) return query(l, r, rt << 1);
// 	else if (l > m) return query(l, r, rt << 1 | 1);
// 	else return query(1, m, rt << 1) + query(m + 1, r, rt << 1 | 1);
// }
//
// int main()
// {
// 	int t;
//   int n;
//   int l,r,c;
// 	while(scanf("%d", &t)!=EOF){
//     for(int i=1;i<=t;i++)scanf("%d",&a[i]);
//     scanf("%d",&n);
//     while(n--){
//       scanf("%d%d%d",&c,&l,&r);
//         if(c=='0')update(l,r,1);
//         else printf("%lld\n",query(l,r,1));
//
//     }
//
//   }
//
// 	return 0;
// }
//
//
//
//
//
//
//
//
//
