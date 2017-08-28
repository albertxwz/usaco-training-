/*
TASK:milk4
LANG:C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int q, n, bv[105], need[105], maxd;
bool f[20005];

bool dp(int x)
{
	memset(f, false, sizeof(f));
	f[0] = true;
	for (int i = 0; i < maxd; ++i)
		for (int j = need[i]; j <= q; ++j)
			f[j] = f[j] || f[j - need[i]];
	return f[q];
}

bool dfsid(int s, int last)
{
	if (s == maxd)
	{
		if (dp(0))
		{
			printf("%d", maxd);
			for (int i = 0; i < maxd; ++i) printf(" %d", need[i]);
			printf("\n");
			return true;
		}
		return false;
	}
	for (int i = last; i < n; ++i)
	{
		need[s] = bv[i];
		if (dfsid(s + 1, i + 1)) return true;
	}
	return false;
}

int main()
{
	freopen("milk4.in", "r", stdin);
	freopen("milk4.out", "w", stdout);
	scanf("%d%d", &q, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &bv[i]);
	sort(bv, bv + n);
	for (maxd = 1; maxd <= n; ++maxd)
		if (dfsid(0, 0)) break;
	return 0;
}
