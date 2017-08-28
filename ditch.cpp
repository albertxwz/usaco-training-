/*
TASK:ditch
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAXN=205,INF=0x7fffffff;
int d[MAXN],cur[MAXN],first[MAXN],from[MAXN*2],to[MAXN*2],flow[MAXN*2],cap[MAXN*2],next[MAXN*2];
int n,m,tots,ans;

void add(int a,int b,int c)
{
	from[tots]=a;
	to[tots]=b;
	flow[tots]=0;
	cap[tots]=c;
	next[tots]=first[a];
	first[a]=tots++;
}

bool BFS()
{
	int Q[MAXN],h=0,t=0;
	memset(d,0,sizeof(d));
	Q[t++]=1;
	d[1]=1;
	while(h<t)
	{
		int x=Q[h]; ++h;
		for(int i=first[x];i!=-1;i=next[i])
		{
			if(d[to[i]]==0 && flow[i]<cap[i])
			{
				d[to[i]]=d[x]+1;
				Q[t++]=to[i];
			}	
		}
	}
	if(d[m])return true;
	else return false;
}

int DFS(int x,int a)
{
	if(x==m || a==0)return a;
	int f=0,tmp;
	for(int &i=cur[x];i!=-1;i=next[i])
	{
		if(d[x]+1==d[to[i]] && (tmp=DFS(to[i],min(cap[i]-flow[i],a)))>0)
		{
			flow[i]+=tmp;
			flow[i^1]-=tmp;
			f+=tmp;
			a-=tmp;
		}
		if(a==0)break;
	}
	return f;
}

int main()
{
	freopen("ditch.in","r",stdin);
	freopen("ditch.out","w",stdout);
	scanf("%d %d",&n,&m);
	tots=0;
	memset(first,-1,sizeof(first));
	while(n--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c);
		add(b,a,0);
	}
	ans=0;
	while(BFS())
	{
		memcpy(cur,first,sizeof(first));
		ans+=DFS(1,INF);
	}
	printf("%d\n",ans);
	//system("pause");
	return 0;
}
