#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MOD = 1000000007;

int r, c, K, num[105], f[105];
int fenwick[105][10005];

int lowbit(int x)
{
	return x & (-x);
}

void update(int x, int delx, int w)
{
	while (x <= K)
	{
		fenwick[w][x] = (fenwick[w][x] + delx) % MOD;
		x += lowbit(x);
	}
}

int query(int x, int w)
{
	int sum = 0;
	while (x > 0)
	{
		sum = (sum + fenwick[w][x]) % MOD;
		x -= lowbit(x);
	}
	return sum;
}

int main()
{
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	scanf("%d%d%d", &r, &c, &K);
	memset(fenwick, 0, sizeof(fenwick));
	for (int i = 0; i < r; ++i)
	{
		memset(f, 0, sizeof(f));
		for (int j = 0; j < c; ++j)
		{
			scanf("%d", &num[j]);
			if (i == 0) continue;
			for (int k = 0; k < j; ++k)
				f[j] = ((f[j] + query(num[j] - 1, k)) % MOD + (query(K, k) - query(num[j], k) + MOD) % MOD) % MOD;
		}
		for (int j = 0; j < c; ++j)
		{
			if (i == 0 && j == 0) update(num[0], 1, j);
			else if (f[j]) update(num[j], f[j], j);
		}
	}
	printf("%d\n", f[c - 1]);
	return 0;
}
