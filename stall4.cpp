/*
TASK:stall4
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAXN=410,INF=0x7fffffff;
struct Edge
{
	int from,to,flow,cap,next;
	
	Edge(){}
	Edge(int u,int v,int f,int c):from(u),to(v),flow(f),cap(c){}
}edges[MAXN*MAXN];
int d[MAXN],first[MAXN],cur[MAXN];
int n,m,tots,ans;

void add(int a,int b,int c)
{
	edges[tots]=Edge(a,b,0,c);
	edges[tots].next=first[a];
	first[a]=tots++;
}

bool BFS()
{
	int Q[MAXN],h=0,t=0;
	memset(d,0,sizeof(d));
	Q[t++]=0;
	d[0]=1;
	while(h<t)
	{
		int x=Q[h++];
		for(int i=first[x];i!=-1;i=edges[i].next)
		{
			Edge &e=edges[i];
			if(d[e.to]==0 && e.flow<e.cap)
			{
				d[e.to]=d[x]+1;
				Q[t++]=e.to;
			}
		}
	}
	return d[1];
}

int DFS(int x,int a)
{
	if(x==1 || a==0)return a;
	int flow=0,f;
	for(int &i=cur[x];i!=-1;i=edges[i].next)
	{
		Edge &e=edges[i];
		if(d[x]+1==d[e.to] && (f=DFS(e.to,min(e.cap-e.flow,a)))>0)
		{
			e.flow+=f;
			edges[i^1].flow-=f;
			flow+=f;
			a-=f;
		}
		if(a==0)break;
	}
	return flow;
}

int main()
{
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);
	scanf("%d %d",&n,&m);
	memset(first,-1,sizeof(first));
	for(int i=0;i<n;++i)
	{
		int vex;
		scanf("%d",&vex);
		while(vex--)
		{
			int to;
			scanf("%d",&to);
			add(i+2,n+to+1,1);
			add(n+to+1,i+2,0);
		}
		add(0,i+2,1);
		add(i+2,0,0);
	}
	for(int i=1;i<=m;++i)
	{
		add(n+i+1,1,1);
		add(1,n+i+1,0);
	}
	ans=0;
	while(BFS())
	{
		memcpy(cur,first,sizeof(first));
		ans+=DFS(0,INF);
	}
	printf("%d\n",ans);
	//system("pause");
	return 0;
}
