/*
TASK:frameup
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int loc[26][4];
int f[26];
int d[26];
int top;
int h;
int w;
int n;
int lens;
char mat[35][35];
bool g[26][26];
bool v[26];
string ans[10000];

int judge(int a,int b)
{
	return a != -1 ? a : b;
}

void dfs_print(int x)
{
	if (x == n)
	{
		for (int i = n - 1; i >= 0; --i) ans[lens] += f[i] + 'A';
		lens++;
		return;
	}
	for (int i = 25; i >= 0; --i)
		if (v[i] && d[i] == 0)
		{
			for (int j = 0; j < 26; ++j)
				if (g[i][j]) --d[j];
			v[i] = false;
			f[top++] = i;
			dfs_print(x + 1);
			v[i] = true;
			for (int j = 0; j < 26; ++j)
				if (g[i][j]) ++d[j];
			top--;
		}
}

int main()
{
	freopen("frameup.in", "r", stdin);
	freopen("frameup.out", "w", stdout);
	
	memset(loc, -1, sizeof(loc));
	memset(v, false, sizeof(v));
	scanf("%d %d", &h, &w);
	n = 0;
	for (int i = 0; i < h; ++i)
	{
		scanf("%s", mat[i]);
		for (int j = 0; j < w; ++j)
		if (mat[i][j] != '.'){
			int c = mat[i][j] - 'A';
			if (!v[c]) ++n;
			v[c] = true;
			loc[c][0] = min(judge(loc[c][0], i), i);
			loc[c][1] = min(judge(loc[c][1], j), j);
			loc[c][2] = max(judge(loc[c][2], i), i);
			loc[c][3] = max(judge(loc[c][3], j), j);
		}
	}
	memset(g, false, sizeof(g));
	memset(d, 0, sizeof(d));
	for (int i = 0; i < 26; ++i)
	{
		if (v[i])
		{
			for (int j = 0; j < 4; ++j)
			{
				if (j % 2)
				{
					for (int k = loc[i][0]; k <= loc[i][2]; ++k)
					{
						int y = loc[i][j];
						if (mat[k][y] - 'A' != i && !g[mat[k][y] - 'A'][i])
						{
							g[mat[k][y] - 'A'][i] = true;
							d[i]++;
						}
					}
				}
				else
				{
					for (int k = loc[i][1]; k <= loc[i][3]; ++k)
					{
						int x = loc[i][j];
						if (mat[x][k] - 'A' != i && !g[mat[x][k] - 'A'][i])
						{
							g[mat[x][k] - 'A'][i] = true;
							d[i]++;
						}
					}
				}
			}
		}
	}
	
	lens = 0;
	dfs_print(0);
	sort(ans, ans + lens);
	for (int i = 0; i < lens; ++i) cout << ans[i] << endl;
	
	return 0;
}
