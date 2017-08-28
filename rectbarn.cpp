/*
TASK:rectbarn
LANG:C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXP = 30005;
const int MAXN = 3005;
const int INF = 0x7fffffff;

int r, c, p, cur, last, ans;
int len[MAXN], left[2][MAXN], right[2][MAXN];
bool g[MAXN][MAXN];

int main()
{
	freopen("rectbarn.in", "r", stdin);
	freopen("rectbarn.out", "w", stdout);
	scanf("%d%d%d", &r, &c, &p);
	memset(g, false, sizeof(g));
	for (int i = 0; i < p; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		g[x][y] = true;
	}
	cur = ans = 0;
	memset(len, 0, sizeof(len));
	memset(left, 0x7f, sizeof(left));
	memset(right, 0x7f, sizeof(right));
	for (int i = 1; i <= r; ++i)
	{
		memset(left[cur], 0x7f, sizeof(left[cur]));
		memset(right[cur], 0x7f, sizeof(right[cur]));
		last = 0;
		for (int j = 1; j <= c; ++j)
			if (!g[i][j]) left[cur][j] = min(left[cur ^ 1][j], j - last - 1), len[j]++;
			else last = j, len[j] = 0;
		last = c + 1;
		for (int j = c; j >= 1; --j)
			if (!g[i][j]) right[cur][j] = min(right[cur ^ 1][j], last - j - 1);
			else last = j;
		for (int j = 1; j <= c; ++j)
			if (!g[i][j]) ans = max(ans, len[j] * (left[cur][j] + right[cur][j] + 1));
		cur ^= 1;
	}
	printf("%d\n", ans);
	return 0;
}
