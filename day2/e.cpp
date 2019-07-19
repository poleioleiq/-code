#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int aa[maxn];
struct node{
  int value;
}node[maxn];

int cmp(node a,node b){

}



int main()
{
	int n, m;

	while (~scanf("%d%d", &n, &m)) {

		int id1, id2;
		memset(aa, 0, sizeof(aa));
		for (int i = 0; i < m; i++) {
			cin >> id1 >> id2;
			aa[id1]++;

		}

		sort(aa, aa + n, less<int>());
		for (int i = 0; i < n; i++) cout << aa[i] << " ";
	}

	return 0;
}
