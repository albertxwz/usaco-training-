/*
TASK:charrec
LANG:C++
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

const char *str = " abcdefghijklmnopqrstuvwxyz";
char sf[545][25], s[1205][25], rec[1205][3];
int mini[1205][3], f[1205], nf, n, mat[1205][545];
string ss[1205];

void readfont()
{
	FILE *fl;
	fl = fopen("font.in", "r");
	fscanf(fl, "%d", &nf);
	for (int i = 1; i <= nf; ++i) fscanf(fl, "%s", sf[i]);
	fclose(fl);
}

int match(int l1, int l2)
{
	int cnt = 0;
	for (int i = 0; i < 20; ++i)
		if (s[l1][i] != sf[l2][i]) cnt++;
	return cnt;
}

int main()
{
	readfont();
	freopen("charrec.in", "r", stdin);
	freopen("charrec.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%s", s[i]);
	memset(mini, 0x7f, sizeof(mini));
	for (int i = 1; i <= nf; ++i)
		for (int j = 1; j <= n; ++j)
			mat[j][i] = match(j, i);
	
	for (int k = 1; k <= nf; k += 20)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (i + 19 <= n)
			{
				int tmp = 0;
				for (int l = 1; l <= 20; ++l) tmp += mat[i + l - 1][k + l - 1];
				if (tmp < mini[i][1])
				{
					rec[i][1] = (tmp > 120 ? '?' : str[k / 20]);
					mini[i][1] = tmp;
				}
			}
			for (int j = 1; j <= 21; ++j)
			{
				if (j < 21 && i + 18 <= n)
				{
					int tmp = 0;
					for (int l = 1; l < j; ++l) tmp += mat[i + l - 1][k + l - 1];
					for (int l = j; l <= 19; ++l) tmp += mat[i + l - 1][k + l];
					if (tmp < mini[i][0])
					{
						rec[i][0] = (tmp > 120 ? '?' : str[k / 20]);
						mini[i][0] = tmp;
					}
				}
				
				if (i + 20 <= n)
				{
					int tmp = 0;
					for (int l = 1; l < j; ++l) tmp += mat[i + l - 1][k + l - 1];
					for (int l = j; l <= 21; ++l) tmp += mat[i + l][k + l - 1];
					if (tmp < mini[i][2])
					{
						rec[i][2] = (tmp > 120 ? '?' : str[k / 20]);
						mini[i][2] = tmp;
					}
				}
			}
		}
	}
	
	f[0] = 0;
	ss[0] = "";
	for (int i = 1; i < 19; ++i) ss[i] = "?", f[i] = 121;
	for (int i = 19; i <= n; ++i)
	{
		f[i] = f[i - 19] + mini[i - 18][0];
		ss[i] = ss[i - 19] + rec[i - 18][0];
		if (i > 19 && f[i] > f[i - 20] + mini[i - 19][1])
		{
			f[i] = f[i - 20] + mini[i - 19][1];
			ss[i] = ss[i - 20] + rec[i - 19][1];
		}
		if (i > 20 && f[i] > f[i - 21] + mini[i - 20][2])
		{
			f[i] = f[i - 21] + mini[i - 20][2];
			ss[i] = ss[i - 21] + rec[i - 20][2];
		}
	}
	cout << ss[n] << endl;
	return 0;
} 
