/*
TASK:latin
LANG:C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, s[10][10], fact[] = {1, 1, 2, 6, 24, 120, 720, 5040};
bool row[10][10], col[10][10];
long long f[10][100];

long long dfs(int x, int y)
{
	if (x == n) return 1;
	int totn = 0, totlen = 1;
	if (x == 3 && y == 2)
	{
		int v[10];
		memset(v, true, sizeof(v));
		for (int i = 1; i <= n; ++i)
			if (v[i])
			{
				int len = 0, st = i;
				totn++;
				for (;;)
				{
					len++;
					v[st] = false;
					st = s[2][st];
					if (!v[st]) break;
				}
				totlen *= len;
			}
		if (f[totn][totlen] != -1) return f[totn][totlen];
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		if (row[x][i] && col[y][i])
		{
			row[x][i] = col[y][i] = false;
			s[x][y] = i;
			if (y == n) ans += dfs(x + 1, 2);
			else ans += dfs(x, y + 1);
			row[x][i] = col[y][i] = true;
		}
	if (x == 3 && y == 2) return f[totn][totlen] = ans;
	else return ans;
}

int main()
{
	freopen("latin.in", "r", stdin);
	freopen("latin.out", "w", stdout);
	scanf("%d", &n);
	memset(row, true, sizeof(row));
	memset(col, true, sizeof(col));
	for (int i = 1; i <= n; ++i)
	{
		row[i][i] = false;
		col[i][i] = false;
		s[1][i] = s[i][1] = i;
	}
	memset(f, -1, sizeof(f));
	cout << dfs(2, 2) * fact[n-1] << endl;
	return 0;
}
