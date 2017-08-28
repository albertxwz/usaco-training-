/*
TASK:picture
LANG:C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 5005;
const int RANGE = 10001;

struct Matrix
{
	int x[2], y[2];
}matrix[MAXN];

struct Line
{
	int h, l, r, delx;
	
	bool operator < (const Line &b) const
	{
		return h < b.h;
	}
	
}line[MAXN << 1];

int n, ans, nl, xcnt, ycnt;
int leftv[RANGE << 5], rightv[RANGE << 5], lazytag[RANGE << 5], minv[RANGE << 5], maxv[RANGE << 5];

void maintain(int o)
{
	int lc = o << 1, rc = lc + 1;
	leftv[o] = leftv[lc];
	rightv[o] = rightv[rc];
	minv[o] = min(minv[lc], minv[rc]);
	maxv[o] = max(maxv[lc], maxv[rc]);
}

void pushdown(int o)
{
	int lc = o << 1, rc = lc + 1;
	if (lazytag[o])
	{
		minv[lc] += lazytag[o];
		maxv[lc] += lazytag[o];
		minv[rc] += lazytag[o];
		maxv[rc] += lazytag[o];
		leftv[lc] += lazytag[o];
		leftv[rc] += lazytag[o];
		rightv[lc] += lazytag[o];
		rightv[rc] += lazytag[o];
		lazytag[lc] += lazytag[o];
		lazytag[rc] += lazytag[o];
		lazytag[o] = 0;
	}
}

void update(int o, int L, int R, int y1, int y2, int dx)
{
	if (y1 <= L && R <= y2)
	{
		leftv[o] += dx;
		rightv[o] += dx;
		minv[o] += dx;
		maxv[o] += dx;
		lazytag[o] += dx;
		return;
	}
	pushdown(o);
	int mid = (L + R) >> 1;
	int lc = o << 1, rc = lc + 1;
	if (mid >= y1) update(lc, L, mid, y1, y2, dx);
	if (mid + 1 <= y2) update(rc, mid + 1, R, y1, y2, dx);
	maintain(o);
}

int query(int o, int L, int R)
{
	if (minv[o] > 0) return 1;
	if (maxv[o] == 0) return 0;
	pushdown(o);
	int mid = (L + R) >> 1;
	int lc = o << 1, rc = lc + 1;
	int a = query(lc, L, mid), b = query(rc, mid + 1, R);
	if (rightv[lc] && leftv[rc]) return a + b - 1;
	else return a + b;
}

void work(int cur)
{
	nl = 0;
	for (int i = 0; i < n; ++i)
		if (cur == 0)
		{
			line[nl].h = matrix[i].x[0];
			line[nl].l = matrix[i].y[0];
			line[nl].r = matrix[i].y[1];
			line[nl++].delx = 1;
			
			line[nl].h = matrix[i].x[1];
			line[nl].l = matrix[i].y[0];
			line[nl].r = matrix[i].y[1];
			line[nl++].delx = -1;
		}
		else
		{
			line[nl].h = matrix[i].y[0];
			line[nl].l = matrix[i].x[0];
			line[nl].r = matrix[i].x[1];
			line[nl++].delx = 1;
			
			line[nl].h = matrix[i].y[1];
			line[nl].l = matrix[i].x[0];
			line[nl].r = matrix[i].x[1];
			line[nl++].delx = -1;
		}
	
	sort(line, line + nl);
	
	memset(leftv, 0, sizeof(leftv));
	memset(rightv, 0, sizeof(rightv));
	memset(maxv, 0, sizeof(maxv));
	memset(minv, 0, sizeof(minv));
	memset(lazytag, 0, sizeof(lazytag));
	memset(minv, 0, sizeof(minv));
	for (int i = 0; i < nl - 1; ++i)
	{
		update(1, 1, 4 * RANGE, 2 * (line[i].l + RANGE - 1), 2 * (line[i].r + RANGE - 1), line[i].delx);
		ans += query(1, 1, 4 * RANGE) * 2 * (line[i + 1].h - line[i].h);
	}
}

int main()
{
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	scanf("%d", &n);
	xcnt = ycnt = 0;
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d%d", &matrix[i].x[0], &matrix[i].y[0], &matrix[i].x[1], &matrix[i].y[1]);
	ans = 0;
	work(0);
	work(1);
	printf("%d\n", ans);
	return 0;
}
