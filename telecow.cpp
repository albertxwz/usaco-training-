/*
TASK:telecow
LANG:C++
*/
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x7fffffff;

struct Edge
{
	int c, f;
	bool canget;
	
	Edge() {
		canget = false;
	}
	
	Edge(int cap, int flow) : c(cap), f(flow) {
		canget = true;
	}
	
}net[205][205];

int n, m, c1, c2, netflow, d[205], side[605][2];

bool BFS()
{
	memset(d, 0, sizeof(d));
	d[2 * c1] = 1;
	queue<int> Q;
	Q.push(2 * c1);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for (int i = 1; i <= 2 * n; ++i)
			if (d[i] == 0 && net[x][i].canget && net[x][i].f < net[x][i].c)
			{
				d[i] = d[x] + 1;
				Q.push(i);
			}
	}
	return d[2 * c2 - 1];
}

int DFS(int x, int a)
{
	if (x == 2 * c2 - 1 || a == 0) return a;
	int flow = 0;
	for (int i = 1; i <= 2 * n; ++i)
	{
		int fw;
		if (d[x] + 1 == d[i] && (fw = DFS(i, min(a, net[x][i].c - net[x][i].f))) > 0)
		{
			net[x][i].f += fw;
			net[i][x].f -= fw;
			flow += fw;
			a -= fw;
		}
		if (a == 0) break;
	}
	return flow;
}

int main()
{
	freopen("telecow.in", "r", stdin);
	freopen("telecow.out", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for (int i = 1; i <= n; ++i)
	{
		net[2 * i - 1][2 * i] = Edge(1, 0);
		net[2 * i][2 * i - 1] = Edge(0, -1);
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		side[i][0] = a;
		side[i][1] = b;
		net[2 * a][2 * b - 1] = Edge(INF, 0);
		net[2 * b - 1][2 * a] = Edge(0, 0);
		net[2 * b][2 * a - 1] = Edge(INF, 0);
		net[2 * a - 1][2 * b] = Edge(0, 0);
	}
	netflow = 0;
	net[2 * c1 - 1][2 * c1].canget = net[2 * c1][2 * c1 - 1].canget = false;
	net[2 * c2 - 1][2 * c2].canget = net[2 * c2][2 * c2 - 1].canget = false;
	while (BFS())
	{
		netflow += DFS(2 * c1, INF);
	}
	printf("%d\n", netflow);
	for (int k = 1; k <= n; ++k)
	{
		if (k == c1 || k == c2) continue;
		for (int i = 1; i <= n; ++i)
		if (net[2 * i - 1][2 * i].canget){
			net[2 * i - 1][2 * i] = Edge(1, 0);
			net[2 * i][2 * i - 1] = Edge(0, -1);
		}
		net[2 * k - 1][2 * k].canget = net[2 * k][2 * k - 1].canget = false;
		for (int i = 0; i < m; ++i)
		{
			int a = side[i][0], b = side[i][1];
			net[2 * a][2 * b - 1] = Edge(INF, 0);
			net[2 * b - 1][2 * a] = Edge(0, 0);
			net[2 * b][2 * a - 1] = Edge(INF, 0);
			net[2 * a - 1][2 * b] = Edge(0, 0);
		}
		int sumflow = 0;
		while (BFS())
		{
			sumflow += DFS(2 * c1, INF);
		}
		if (sumflow < netflow)
		{
			netflow = sumflow;
			printf("%d", k);
			if (netflow == 0) break;
			else printf(" ");
		}
		else
		{
			net[2 * k - 1][2 * k].canget = net[2 * k][2 * k - 1].canget = true;
		}
	}
	printf("\n");
	return 0;
}
