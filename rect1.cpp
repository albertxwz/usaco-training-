/*
TASK:rect1
LANG:C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Matrix
{
	int x1, y1, x2, y2, cr;
}mat[1005];

int cnt[2505], n;

int floatup(int x1, int y1, int x2, int y2, int k)
{
	if (x2 < x1 || y2 < y1) return 0;
	if (k == n + 1) return (x2 - x1 + 1) * (y2 - y1 + 1);
	if (x1 > mat[k].x2 || x2 < mat[k].x1 || y1 > mat[k].y2 || y2 < mat[k].y1)
		return floatup(x1, y1, x2, y2, k + 1);
	return floatup(x1, y1, mat[k].x1 - 1, y2, k + 1)
			+ floatup(max(x1, mat[k].x1), y1, min(x2, mat[k].x2), mat[k].y1 - 1, k + 1)
			+ floatup(max(x1, mat[k].x1), mat[k].y2 + 1, min(x2, mat[k].x2), y2, k + 1)
			+ floatup(mat[k].x2 + 1, y1, x2, y2, k + 1);
}

int main()
{
	freopen("rect1.in", "r", stdin);
	freopen("rect1.out", "w", stdout);
	mat[0].x1 = mat[0].y1 = 0;
	mat[0].cr = 1;
	scanf("%d%d%d", &mat[0].x2, &mat[0].y2, &n);
	mat[0].x2--;
	mat[0].y2--;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d%d%d", &mat[i].x1, &mat[i].y1, &mat[i].x2, &mat[i].y2, &mat[i].cr);
		mat[i].x1 = max(mat[i].x1, mat[0].x1);
		mat[i].y1 = max(mat[i].y1, mat[0].y1);
		mat[i].x2 = min(mat[i].x2-1, mat[0].x2);
		mat[i].y2 = min(mat[i].y2-1, mat[0].y2);
	}
	memset(cnt, 0, sizeof(cnt));
	cnt[mat[n].cr] = (mat[n].x2 - mat[n].x1 + 1) * (mat[n].y2 - mat[n].y1 + 1);
	for (int i = n-1; i >= 0; --i)
		cnt[mat[i].cr] += floatup(mat[i].x1, mat[i].y1, mat[i].x2, mat[i].y2, i + 1);
	for (int i = 1; i <= 2500; ++i)
		if (cnt[i]) printf("%d %d\n", i, cnt[i]);
	return 0;
}
