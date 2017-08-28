/*
TASK:vans
LANG:C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Bigint
{
	static const int BASE = 10000;
	int s[200], len;
	
	Bigint()
	{
		memset(s, 0, sizeof(s));
		len = 1;
	}
	
	Bigint operator + (const Bigint &b)
	{
		Bigint c;
		c.len = max(len, b.len);
		for (int i = 0; i < c.len; ++i)
		{
			c.s[i] += s[i] + b.s[i];
			c.s[i + 1] = c.s[i] / BASE;
			c.s[i] %= BASE;
		}
		if (c.s[c.len]) c.len++;
		return c;
	}
};

int n;
Bigint f[1005], g[1005], s[1005];

int main()
{
	freopen("vans.in", "r", stdin);
	freopen("vans.out", "w", stdout);
	scanf("%d", &n);
	f[1].s[0] = 0;
	f[2].s[0] = 2;
	g[1].s[0] = 2;
	s[1].s[0] = 0;
	g[2].s[0] = 2;
	s[2].s[0] = 2;
	for (int i = 3; i <= n; ++i)
	{
		f[i] = f[i - 1] + g[i - 1];
		s[i] = f[i - 2] + f[i - 2] + s[i - 1];
		g[i] = f[i - 1] + f[i - 1] + g[i - 2] + s[i];
	}
	printf("%d", f[n].s[f[n].len - 1]);
	for (int i = f[n].len - 2; i >= 0; --i) printf("%04d", f[n].s[i]);
	printf("\n");
	return 0;
}
