/*
TASK:fc
LANG:C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 10005;
const double EPS = 1e-10;

struct Vertex
{
	double x, y;
	
	Vertex() {
	}
	
	Vertex(double x0, double y0) : x(x0), y(y0) {
	}
	
	bool operator < (const Vertex &A) const
	{
		return x < A.x || (abs(x - A.x) <= EPS && y < A.y);
	}
	
	Vertex operator - (const Vertex &A)
	{
		return Vertex(x - A.x, y - A.y);
	}
	
}v[MAXN], ch[MAXN];

double Cross(Vertex A, Vertex B)
{
	return A.x * B.y - A.y * B.x;
}

double sqr(double x)
{
	return x * x;
}

double Distance(Vertex A, Vertex B)
{
	return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}

int n;

int main()
{
	freopen("fc.in", "r", stdin);
	freopen("fc.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lf%lf", &v[i].x, &v[i].y);
	sort(v, v + n);
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], v[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = v[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; --i)
	{
		while (m > k && Cross(ch[m - 1] - ch[m - 2], v[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = v[i];
	}
	double ans = 0;
	for (int i = 0; i < m - 1; ++i)
		ans += Distance(ch[i], ch[i + 1]);
	printf("%.2lf\n", ans);
	return 0;
}
