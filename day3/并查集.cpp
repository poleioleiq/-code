int pre[100005];
int find(int x)
{
	int r = x;

	while (pre[r] != x) {
		r = pre[r];
	}
	return r;
}
void join(int x, int y )
{
	int fx = find(x);
	int fy = find(y);

	if (fx != fy)
		pre[fx] = fy;
}
