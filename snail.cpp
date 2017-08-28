/*
TASK:snail
LANG:C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int d[2][4] = {{0, -1, 0, 1},
					 {-1, 0, 1, 0}};
					 
int n, ans;
bool barrier[125][125], vis[125][125];

void read()
{
	int b;
	scanf("%d%d", &n, &b);
	memset(barrier, false, sizeof(barrier));
	while (b--)
	{
		char s[10];
		scanf("%s", s);
		char c;
		int x;
		sscanf(s, "%c%d", &c, &x);
		int y = c - 'A' + 1;
		barrier[x][y] = true;
	}
}

bool test(int x, int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void dfs(int x0, int y0, int k, int step)
{
	ans = max(ans, step);
	int x = x0 + d[0][k], y = y0 + d[1][k];
	if (test(x, y) && !vis[x][y]) return;
	vis[x0][y0] = false;
	if (test(x, y) && !barrier[x][y]) dfs(x, y, k, step + 1);
	else
	{
		int dir = (k + 3) % 4;
		x = x0 + d[0][dir];
		y = y0 + d[1][dir];
		if (test(x, y) && !barrier[x][y] && vis[x][y]) dfs(x, y, dir, step + 1);
		dir = (k + 1) % 4;
		x = x0 + d[0][dir];
		y = y0 + d[1][dir];
		if (test(x, y) && !barrier[x][y] && vis[x][y]) dfs(x, y, dir, step + 1);
	}
	vis[x0][y0] = true;
}

int main()
{
	freopen("snail.in", "r", stdin);
	freopen("snail.out", "w", stdout);
	read();
	memset(vis, true, sizeof(vis));
	ans = 0;
	dfs(1, 1, 2, 1);
	dfs(1, 1, 3, 1);
	printf("%d\n", ans);
	return 0;
}
