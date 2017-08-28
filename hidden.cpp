/*
TASK:hidden
LANG:C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

char s[MAXN];
int sa[MAXN], c[MAXN], x[MAXN], y[MAXN], n;

int main()
{
	freopen("hidden.in", "r", stdin);
	freopen("hidden.out", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 0; i < n / 72 + 1; ++i)
	{
		for (int j = i * 72; j < i * 72 + 72 && j < n; ++j)
			scanf("%c", &s[j]);
		getchar();
	}
	for (int i = n; i < 2 * n - 1; ++i) s[i] = s[i % n];
	n = 2 * n - 1;
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; ++i) c[s[i]]++, x[i] = s[i];
	for (int i = 1; i < MAXN; ++i) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; --i) sa[--c[s[i]]] = i;
	int p;
	for (int k = 1; k <= n; k <<= 1)
	{
		p = 0;
		for (int i = n - k; i < n; ++i) y[p++] = i;
		for (int i = 0; i < n; ++i) if (sa[i] >= k) y[p++] = sa[i] - k;
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; ++i) c[x[y[i]]]++;
		for (int i = 1; i < MAXN; ++i) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
		swap(x, y);
		p = 1;
		x[sa[0]] = 0;
		for (int i = 1; i < n; ++i)
			x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? p - 1 : p++);
		if (p >= n) break;
	}
	if (p < n) printf("0\n");
	else
	{
		int ansloc = 0;
		while (sa[ansloc] >= (n + 1) / 2) ansloc++;
		printf("%d\n", sa[ansloc]);
	}
	return 0;
}
