#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void preorder(ninode*rt)
{
	if (rt == nill) return;
	else {
		pritf(rt->data);
		preorder(rt->lson);
		preorder(rt->rson);//1访问跟节点2.前序遍历左子树，前序遍shu历右子树

		preorder(rt->lson);
		printf(rt->data);
		preorder(rt->rson);

		preorder(rt->lson);
		preorder(rt->rson);
		printf(rt->data);
	}
}
void preo(binode*root)
{
	initstack(s);
	while (root != null || stackempty(s)) {
		while (root != null) {
			cout << root->data;
			pushu(s, root);
			root = root->lson;
		}
		if (!emptystack(s)) {
			root = pop(s)
			       root = root->rson;//连通图之任何两i点之间都是联通的，有向的称为强连通图

		}
	}
}
