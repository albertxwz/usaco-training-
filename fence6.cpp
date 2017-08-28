/*
TASK:fence6
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAXN=105,MOD=9991;
int g[MAXN][MAXN],f[MAXN][MAXN],left[MAXN][10],right[MAXN][10],vetex[2][MAXN],ans,totv,n;
bool appear[MAXN];

int find(int t1,int t2)
{
	for(int i=1;i<=left[t1][0];++i)
		if(t2==left[t1][i])return vetex[0][t1];
	return vetex[1][t1];
}

int main()
{
	freopen("fence6.in","r",stdin);
	freopen("fence6.out","w",stdout);
	scanf("%d",&n);
	totv=0;
	memset(appear,false,sizeof(appear));
	memset(g,0xf,sizeof(g));
	for(int i=0;i<n;++i)
	{
		int s,length,n1s,n2s,mint=MAXN,l,r;
		scanf("%d %d %d %d",&s,&length,&n1s,&n2s);
		appear[s]=true;
		left[s][0]=n1s;
		right[s][0]=n2s;
		for(int i=1;i<=n1s;++i)
		{
			scanf("%d",&left[s][i]);
			if(appear[left[s][i]])mint=left[s][i];
		}
		if(mint!=MAXN)l=find(mint,s);
		else l=totv++;
		mint=MAXN;
		for(int i=1;i<=n2s;++i)
		{
			scanf("%d",&right[s][i]);
			if(appear[right[s][i]])mint=right[s][i];
		}
		if(mint!=MAXN)r=find(mint,s);
		else r=totv++;
		g[l][r]=g[r][l]=length;
		vetex[0][s]=l;
		vetex[1][s]=r;
	}
	ans=0x7fffffff;
	memcpy(f,g,sizeof(g));
	for(int k=0;k<totv;++k)
	{
		for(int i=0;i<k;++i)
			for(int j=i+1;j<k;++j)
				ans=min(ans,f[i][j]+g[i][k]+g[k][j]);
		for(int i=0;i<totv;++i)
			for(int j=0;j<totv;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	printf("%d\n",ans);
	//system("pause");
	return 0;
}
