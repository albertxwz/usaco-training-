/*
TASK:fence4
LANG:C++
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct Vector
{
	double x, y;
	
	Vector(double x=0, double y=0) : x(x), y(y)
	{
	}
	
	Vector operator + (Vector rbs)
	{
		return Vector(x + rbs.x, y + rbs.y);
	}
	
	Vector operator - (Vector rbs)
	{
		return Vector(x - rbs.x, y - rbs.y);
	}
	
	Vector operator * (double vari)
	{
		return Vector(x * vari, y * vari);
	}
	
}v[205], per;

const double eps = 1e-10;
int dcmp(double x)
{
	if (fabs(x) < eps) return 0;
	else return x < 0 ? -1 : 1;
}

double cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}

bool judge(Vector a1, Vector a2, Vector b1, Vector b2)
{
	double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
	double c3 = cross(b2 - b1, a1 - b1), c4 = cross(b2 - b1, a2 - b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

bool judge2(Vector a1, Vector a2, Vector b1, Vector b2)
{
	double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
	return dcmp(c1) * dcmp(c2) < 0;
}

Vector getv(Vector P, Vector v, Vector Q, Vector w)
{
	Vector u = P - Q;
	double t = cross(w, u) / cross(v, w);
	return P + (v * t);
}

double sqr(double x)
{
	return x * x;
}

double dist(Vector a, Vector b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int n, ansn, ans[205][2];
double mindis[205];
bool coverv[205];

int main()
{
	freopen("fence4.in", "r", stdin);
	freopen("fence4.out", "w", stdout);
	scanf("%d", &n);
	scanf("%lf%lf", &per.x, &per.y);
	for (int i = 0; i < n; ++i) scanf("%lf%lf", &v[i].x, &v[i].y);
	bool flag = true;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 2; j < n; ++j)
			if (judge(v[i], v[(i+1) % n], v[j], v[(j+1) % n]))
			{
				flag = false;
				break;
			}
		if (!flag) break;
	}
	if (!flag) printf("NOFENCE\n");
	else
	{
		for (int i = 0; i < n; ++i) mindis[i] = 1e20;
		memset(coverv, false, sizeof(coverv));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (j != i && j+1 != i)
				{
					if (judge2(per, v[i], v[j], v[(j+1) % n]))
					{
						Vector tmpv = getv(per, per-v[i], v[j], v[j]-v[(j+1) % n]);
						if (dcmp(tmpv.x-per.x) * dcmp(v[i].x-per.x) < 0 || dcmp(tmpv.y-per.y) * dcmp(v[i].y-per.y) < 0) continue;
						mindis[i] = min(mindis[i], dist(per, tmpv));
					}
				}
				if (i != j && cross(v[i]-per, v[j]-per) == 0)
				{
					if (dcmp(v[j].x-per.x) * dcmp(v[i].x-per.x) < 0 || dcmp(v[j].y-per.y) * dcmp(v[i].y-per.y) < 0) continue;
					if (dist(v[i], per) < dist(v[j], per)) coverv[j] = true;
					else coverv[i] = true;
				}
			}
		}
		ansn = 0;
		for (int i = 0; i < n; ++i)
		{
			if (cross(v[i] - per, v[(i+1) % n] - per) == 0) continue;
			double d1 = dist(per, v[i]), d2 = dist(per, v[(i+1) % n]);
			int j = i;
			bool canbeseen = true;
			if (d1 > mindis[j] || coverv[j])
			{
				for (;;)
				{
					if (j == -1) j = n - 1;
					if (j == (i+1) % n)
					{
						canbeseen = false;
						break;
					}
					if (!coverv[j])
					{
						int left = (j-1+n)%n, right = (j+1)%n;
						if (dcmp(cross(v[j]-per, v[left]-per)) * dcmp(cross(v[j]-per, v[right]-per)) > 0)
							if (judge2(per, v[j], v[i], v[(i+1) % n]))
							{
								Vector tmpv = getv(per, per-v[j], v[i], v[i]-v[(i+1) % n]);
								if (abs(mindis[j] - dist(per, tmpv)) < eps) break;
							}
					}
					j--;
				}
			}
			int tmp = j;
			j = (i+1) % n;
			if (d2 > mindis[j] || coverv[j])
			{
				for (;;)
				{
					if (j == n) j = 0;
					if (j == i)
					{
						canbeseen = false;
						break;
					}
					if (!coverv[j])
					{
						int left = (j-1+n)%n, right = (j+1)%n;
						if (dcmp(cross(v[j]-per, v[left]-per)) * dcmp(cross(v[j]-per, v[right]-per)) > 0)
							if (judge2(per, v[j], v[i], v[(i+1) % n]))
							{
								Vector tmpv = getv(per, per-v[j], v[i], v[i]-v[(i+1) % n]);
								if (abs(mindis[j] - dist(per, tmpv)) < eps) break;
							}
					}
					j++;
				}
			}
			if (canbeseen && (cross(v[tmp] - per, v[j] - per) != 0))
			{
				ans[ansn][0] = i;
				ans[ansn][1] = (i+1) % n;
				if (ans[ansn][1] < ans[ansn][0]) swap(ans[ansn][0], ans[ansn][1]);
				j = ansn;
				ansn++;
				while (j != 0 && ans[j][1] == ans[j-1][1] && ans[j][0] < ans[j-1][0])
				{
					swap(ans[j][0], ans[j-1][0]);
					swap(ans[j][1], ans[j-1][1]);
					j--;
				}
			}
		}
		printf("%d\n", ansn);
		for (int i = 0; i < ansn; ++i)
			printf("%.0lf %.0lf %.0lf %.0lf\n", v[ans[i][0]].x, v[ans[i][0]].y, v[ans[i][1]].x, v[ans[i][1]].y);
	}
	return 0;
}
