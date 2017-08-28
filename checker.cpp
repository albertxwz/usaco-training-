/*
TASK:checker
LANG:C++
*/
#include <cstdio>
#include <cstring>

using namespace std;

bool col[15], zd[30], fd[30];
int prow[15];
int ans, n;

void dfs(int row)
{
	if (row == n)
	{
		ans++;
		if (ans <= 3)
		{
			for (int i = 0; i < n-1; ++i) printf("%d ", prow[i]);
			printf("%d\n", prow[n-1]);
		}
		return;
	}
	for (int i = 0; i < n; ++i)
		if (!col[i] && !zd[row+i] && !fd[row+n-i-1])
		{
			col[i] = zd[row+i] = fd[row+n-i-1] = true;
			prow[row] = i + 1;
			dfs(row + 1);
			col[i] = zd[row+i] = fd[row+n-i-1] = false;
		}
}

int main()
{
	freopen("checker.in", "r", stdin);
	freopen("checker.out", "w", stdout);
	scanf("%d", &n);
	memset(col, 0, sizeof(col));
	memset(zd, 0, sizeof(zd));
	memset(fd, 0, sizeof(fd));
	ans = 0;
	dfs(0);
	printf("%d\n", ans);
	return 0;
}
