/*
TASK:tour
LANG:C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int f[105][105], ans, n, v;
string s1, s2;
map<string, int> getid;
bool g[105][105];

int main()
{
	freopen("tour.in", "r", stdin);
	freopen("tour.out", "w", stdout);
	scanf("%d%d", &n, &v);
	for (int i = 0; i < n; ++i)
	{
		cin >> s1;
		getid[s1] = i;
	}
	memset(g, false, sizeof(g));
	while (v--)
	{
		cin >> s1 >> s2;
		int x = getid[s1], y = getid[s2];
		g[x][y] = g[y][x] = true;
	}
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i <= k; ++i)
			for (int j = 0; j <= k; ++j)
			if (f[i][j] > 0){
				if (k != i && g[j][k]) f[i][k] = max(f[i][k], f[i][j] + 1);
				if (k != j && g[i][k]) f[k][j] = max(f[k][j], f[i][j] + 1);
			}
	ans = 1;
	for (int i = 0; i < n; ++i)
		if (g[i][n - 1])
		for (int j = 0; j < n; ++j)
			if (i != j && g[j][n - 1])
				ans = max(ans, f[i][j] + 1);
	printf("%d\n", ans);
	return 0;
}
