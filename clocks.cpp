/*
TASK:clocks
LANG:C++
*/
#include <cstdio>
#include <cstring>

using namespace std;

const char mtd[9][7] = {"ABDE\0",
						"ABC\0",
						"BCEF\0",
						"ADG\0",
						"BDEFH\0",
						"CFI\0",
						"DEGH\0",
						"GHI\0",
						"EFHI\0"};
const int a[4] = {1, 10, 100, 1000};
const int b[4] = {0, 1, 11, 111};

int clock[9], rot[9], cnt[9], path[30], np, now;

void dfs(int dep, int dnow)
{
	if (dep == 9)
	{
		bool flag = true;
		for (int i = 0; i < 9; ++i)
			if (clock[i] != rot[i] % 4)
			{
				flag = false;
				break;
			}
		if (flag && dnow < now)
		{
			np = 0;
			for (int i = 0; i < 9; ++i)
				for (int j = 0; j < cnt[i]; ++j)
					path[np++] = i + 1;	
			now = dnow;
		}
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		cnt[dep] = i;
		for (int lv = 0; lv < strlen(mtd[dep]); ++lv) rot[mtd[dep][lv] - 'A'] += i;
		dfs(dep + 1, dnow * a[i] + (dep+1) * b[i]);
		for (int lv = 0; lv < strlen(mtd[dep]); ++lv) rot[mtd[dep][lv] - 'A'] -= i;
	}
}

int main()
{
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
	for (int i = 0; i < 9; ++i)
	{
		scanf("%d", &clock[i]);
		clock[i] = (4 - clock[i]/3) % 4;
	}
	memset(rot, 0, sizeof(rot));
	now = 0x7fffffff;
	dfs(0, 0);
	for (int i = 0; i < np-1; ++i) printf("%d ", path[i]);
	printf("%d\n", path[np-1]);
	return 0;
}
