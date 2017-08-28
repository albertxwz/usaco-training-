/*
TASK:packrec
LANG:C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Matrix
{
	int h, w;
	
	bool operator < (const Matrix &b) const
	{
		return h < b.h || h == b.h && w < b.w;
	}
}ans[1024], minmat[4], a[4];

int anslen;
bool v[4];

void judge()
{
	if (ans[anslen].h > ans[anslen].w) swap(ans[anslen].h, ans[anslen].w);
	if (ans[anslen].h * ans[anslen].w < ans[0].h * ans[0].w)
	{
		ans[0] = ans[anslen];
		anslen = 1;
		return;
	}
	if (ans[anslen].h * ans[anslen].w == ans[0].h * ans[0].w) anslen++;
}

void dfs(int s)
{
	if (s == 4)
	{
		//1
		ans[anslen].h = max(minmat[0].h, max(minmat[1].h, max(minmat[2].h, minmat[3].h)));
		ans[anslen].w = minmat[0].w + minmat[1].w + minmat[2].w + minmat[3].w;
		judge();
		//2
		ans[anslen].h = max(minmat[0].h, max(minmat[1].h, minmat[2].h)) + minmat[3].h;
		ans[anslen].w = max(minmat[3].w, minmat[0].w + minmat[1].w + minmat[2].w);
		judge();
		//3
		ans[anslen].h = max(minmat[3].h, max(minmat[0].h, minmat[1].h) + minmat[2].h);
		ans[anslen].w = max(minmat[0].w + minmat[1].w, minmat[2].w) + minmat[3].w;
		judge();
		//4
		ans[anslen].h = max(minmat[0].h, max(minmat[1].h + minmat[2].h, minmat[3].h));
		ans[anslen].w = minmat[0].w + max(minmat[1].w, minmat[2].w) + minmat[3].w;
		judge();
		//5
		ans[anslen].h = max(minmat[0].h, minmat[1].h) + minmat[2].h + minmat[3].h;
		ans[anslen].w = max(minmat[0].w, minmat[1].w) + minmat[2].w + minmat[3].w;
		judge();
		//6
		if (minmat[0].w <= minmat[1].w && minmat[1].h <= minmat[3].h)
		{
			ans[anslen].h = max(minmat[0].h + minmat[1].h, minmat[2].h + minmat[3].h);
			ans[anslen].w = max(minmat[1].w + minmat[3].w, minmat[0].w + minmat[2].w);
			judge();
		}
	}
	
	for (int i = 0; i < 4; ++i)
		if (v[i])
		{
			v[i] = false;
			minmat[s].h = a[i].h;
			minmat[s].w = a[i].w;
			dfs(s+1);
			swap(minmat[s].h, minmat[s].w);
			dfs(s+1);
			v[i] = true;
		}
}

int main()
{
	freopen("packrec.in", "r", stdin);
	freopen("packrec.out", "w", stdout);
	for (int i = 0; i < 4; ++i) scanf("%d %d", &a[i].h, &a[i].w);
	memset(v, true, sizeof(v));
	anslen = 0;
	dfs(0);
	sort(ans, ans + anslen);
	printf("%d\n", ans[0].h * ans[0].w);
	printf("%d %d\n", ans[0].h, ans[0].w);
	for (int i = 1; i < anslen; ++i)
		if (ans[i].h != ans[i - 1].h || ans[i].w != ans[i - 1].w)
			printf("%d %d\n", ans[i].h, ans[i].w);
	return 0;
}
