/*
TASK:cowcycle
LANG:C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int F, R, f1, f2, r1, r2, minfr, maxfr, minbk, maxbk;
int ansfr[5], ansbk[10];
int tmpfr[5], tmpbk[10];
double minvar;

double variance()
{
	double d[50], aver = 0, vari = 0;
	int n = 0;
	for (int i = 0; i < F; ++i)
		for (int j = 0; j < R; ++j)
			d[n++] = (double)tmpfr[i] / tmpbk[j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (d[i] < d[j]) swap(d[i], d[j]);
	for (int i = 0; i < n - 1; ++i)
		d[i] = d[i + 1] - d[i], aver += d[i] / (n - 1);
	n--;
	for (int i = 0; i < n; ++i)
		vari += (d[i] - aver) * (d[i] - aver) / n;
	return vari;
}

bool judge(double vrc)
{
	if (vrc < minvar) return true;
	else if (vrc > minvar) return false;
	for (int i = 0; i < F; ++i)
		if (tmpfr[i] < ansfr[i]) return true;
		else if (tmpfr[i] > ansfr[i]) return false;
	for (int i = 0; i < R; ++i)
		if (tmpbk[i] < ansbk[i]) return true;
		else if (tmpbk[i] > ansbk[i]) return false;
	return false;
}

void dfsbk(int s)
{
	if (s >= R - 1)
	{
		double vrc = variance();
		if (judge(vrc))
		{
			memcpy(ansfr, tmpfr, F * sizeof(int));
			memcpy(ansbk, tmpbk, R * sizeof(int));
			minvar = vrc;
		}
		return;
	}
	for (int i = tmpbk[s-1] + 1; i <= tmpbk[R-1] - R + s + 1; ++i)
	{
		tmpbk[s] = i;
		dfsbk(s + 1);
	}
}

void dfsfr(int s)
{
	if (s >= F - 1)
	{
		dfsbk(1);
		return;
	}
	for (int i = tmpfr[s-1] + 1; i <= tmpfr[F-1] - F + s + 1; ++i)
	{
		tmpfr[s] = i;
		dfsfr(s + 1);
	}
}

int main()
{
	freopen("cowcycle.in", "r", stdin);
	freopen("cowcycle.out", "w", stdout);
	scanf("%d%d%d%d%d%d", &F, &R, &f1, &f2, &r1, &r2);
	minvar = 1.0 * 0x7fffffff;
	for (minfr = f1; minfr <= f2 - F + 1; ++minfr)
		for (maxfr = minfr + F - 1; maxfr <= f2; ++maxfr)
			for (minbk = r1; minbk <= r2 - R + 1; ++minbk)
				for (maxbk = minbk + R - 1; maxbk <= r2; ++maxbk)
					if (maxfr * maxbk >= minfr * minbk * 3)
					{
						tmpfr[0] = minfr;
						tmpfr[F-1] = maxfr;
						tmpbk[0] = minbk;
						tmpbk[R-1] = maxbk;
						dfsfr(1);
					}
	for (int i = 0; i < F - 1; ++i) printf("%d ", ansfr[i]);
	printf("%d\n", ansfr[F-1]);
	for (int i = 0; i < R - 1; ++i) printf("%d ", ansbk[i]);
	printf("%d\n", ansbk[R-1]);
	return 0;
}
