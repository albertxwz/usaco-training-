/*
TASK:milk6
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN = 40;
const int MAXM = 1005;
const int INF = 0x7fffffff;

struct Edge
{
	int from;
	int to;
	int id;
	long long wei;
	
	bool operator < (const Edge &b) const
	{
		return wei > b.wei;
	}
	
};

Edge edges[MAXM];
int d[MAXN];
int stop[MAXM];
long long e[MAXN];
long long cap[MAXN][MAXN];
long long flow[MAXN][MAXN];
int m;
int n;
int maxflow;
int best;
int lens;
bool v[MAXN];

int preflow()
{
	queue<int> Q;
	memset(flow, 0, sizeof(flow));
	memset(e, 0, sizeof(e));
	memset(d, 0, sizeof(d));
	memset(v, true, sizeof(v));
	d[1] = n;
	v[1] = v[n] = false;
	for (int i = 2; i <= n; ++i)
		if (cap[1][i])
		{
			flow[1][i] = cap[1][i];
			flow[i][1] = -cap[1][i];
			e[i] += cap[1][i];
			if (i != n) Q.push(i), v[i] = false;
		}
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for (int i = n; i >= 1; --i)
			if (d[i] + 1 == d[x] && cap[x][i] > flow[x][i])
			{
				int delx = min(e[x], cap[x][i] - flow[x][i]);
				flow[x][i] += delx;
				flow[i][x] -= delx;
				e[x] -= delx;
				e[i] += delx;
				if (v[i]) Q.push(i), v[i] = false;
			}
		if (e[x])
		{
			d[x]++;
			Q.push(x);
		}
		else v[x] = true;
	}
	return e[n];
}

int main()
{
	freopen("milk6.in", "r", stdin);
	freopen("milk6.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		Edge &ed = edges[i];
		scanf("%d %d %d", &ed.from, &ed.to, &ed.wei);
		cap[ed.from][ed.to] += ed.wei;
		ed.id = i + 1;
	}
	
	maxflow = preflow();
	sort(edges, edges + m);

	best = lens = 0;
	for (int i = 0; i < m; ++i)
	{
		Edge &ed = edges[i];
		cap[ed.from][ed.to] -= ed.wei;
		int tflow = preflow();
		if (tflow + ed.wei == maxflow)
		{
			best += ed.wei;
			stop[lens++] = ed.id;
			maxflow = tflow;
		}
		else cap[ed.from][ed.to] += ed.wei;
	}
	printf("%d %d\n", best, lens);
	sort(stop, stop + lens);
	for (int i = 0; i < lens; ++i) printf("%d\n", stop[i]);
	//system("pause");
	return 0;
}
