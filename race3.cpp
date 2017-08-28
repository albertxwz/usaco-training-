/*
TASK:race3
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct Edge
{
	int from, to, next;
	
	Edge() {}
	Edge(int u, int v):from(u), to(v) {}
}edges[105];
int first[55], ans1[55], ans2[55];
int n, tots, len1, len2;
bool v[55], vt[55];

void add(int u, int v)
{
	edges[tots]=Edge(u, v);
	edges[tots].next = first[u];
	first[u] = tots++;
}

void DFS1(int x)
{
	if (!v[x]) return;
	v[x] = false;
	for (int i = first[x]; i != -1; i = edges[i].next)
		DFS1(edges[i].to);
}

bool DFS2(int x)
{
	if (!v[x]) return false;
	if (!vt[x]) return true;
	vt[x] = false;
	bool flag = true;
	for (int i = first[x]; i != -1; i = edges[i].next)
		flag = flag && DFS2(edges[i].to);
	return flag;
}

int main()
{
	freopen("race3.in", "r", stdin);
	freopen("race3.out", "w", stdout);
	n = 0;
	tots = 0;
	memset(first, -1, sizeof(first));
	while (true)
	{
		int x;
		scanf("%d", &x);
		if (x == -1) break;
		while (true)
		{
			if (x == -2) break;
			add(n, x);
			scanf("%d", &x);
		}
		++n;
	}
	--n;
	len1 = len2 = 0;
	for (int i = 0; i <= n; ++i)
	{
		memset(v, true, sizeof(v));
		memset(vt, true, sizeof(vt));
		v[i] = false;
		DFS1(0);
		if (v[n] && i != 0) ans1[len1++] = i;
		v[i] = true;
		if (DFS2(i) && i != 0 && i != n) ans2[len2++] = i;
	}
	printf("%d", len1);
	for (int i = 0; i < len1; ++i) printf(" %d",ans1[i]);
	printf("\n");
	printf("%d", len2);
	for (int i = 0; i < len2; ++i) printf(" %d", ans2[i]);
	printf("\n");
	//system("pause");
	return 0;
}
