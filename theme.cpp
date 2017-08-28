/*
TASK:theme
LANG:C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[5005], f[5005], ans;

void read()
{
	int before, x;
	scanf("%d", &n);
	before = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		a[i] = x - before;
		before = x;
	}
	a[n] = -before;
}

int main()
{
	freopen("theme.in", "r", stdin);
	freopen("theme.out", "w", stdout);
	read();
	ans = 0;
	for (int fr = n - 3; fr >= 5; --fr)
	{
		memset(f, 0, sizeof(f));
		f[0] = f[1] = 0;
		for (int i = fr + 1; i <= n; ++i)
		{
			int j = f[i - fr];
			while (j != 0 && a[i] != a[fr + j]) j = f[j];
			f[i - fr + 1] = (a[i] == a[fr + j]) ? j + 1 : 0;
		}
		int j = 0;
		for (int i = 0; i < fr - 1; ++i)
		{
			while (j != 0 && a[i] != a[fr + j]) j = f[j];
			if (a[i] == a[fr + j])
			{
				j++;
				ans = max(ans, j + 1);
			}
		}
	}
	if (ans < 5) printf("0\n");
	else printf("%d\n", ans);
	return 0;
}
