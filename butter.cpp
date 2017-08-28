/*
ID:10179811
TASK:butter
LANG:C++
#FILE
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int MAXP=805;

struct Edge
{
	int x,y,z,next;
	Edge(){}
	Edge(int a,int b,int c):x(a),y(b),z(c){}
}edges[3000];

int first[MAXP],dis[MAXP],w[MAXP],Q[MAXP*MAXP],h,t,n,p,c,ans,tots;
bool flag[MAXP];

int min(int a,int b){return a<b?a:b;}

int spfa(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(flag,true,sizeof(flag));
	dis[s]=0;
	h=t=0;
	Q[t++]=s;
	flag[s]=false;
	while(h<t)
	{
		int x=Q[h++];
		for(int i=first[x];i!=-1;i=edges[i].next)
			if(dis[x]+edges[i].z<dis[edges[i].y])
			{
				dis[edges[i].y]=dis[x]+edges[i].z;
				if(flag[edges[i].y])
				{
					Q[t++]=edges[i].y;	
					flag[edges[i].y]=false;
				}
			}
		flag[x]=true;
	}
	int sum=0;
	for(int i=1;i<=p;++i)sum+=dis[i]*w[i];
	return sum;
}

void add(int a,int b,int c)
{
	edges[tots]=Edge(a,b,c);
	edges[tots].next=first[a];
	first[a]=tots++;
}

int main()
{
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	scanf("%d %d %d",&n,&p,&c);
	memset(w,0,sizeof(w));
	memset(first,-1,sizeof(first));
	while(n--)
	{
		int x;
		scanf("%d",&x);
		++w[x];
	}
	tots=0;
	while(c--)
	{
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		add(u,v,c);
		add(v,u,c);
	}
	ans=0x7fffffff;
	for(int i=1;i<=p;++i)ans=min(ans,spfa(i));
	printf("%d\n",ans);
	//system("pause");
	return 0;
}
