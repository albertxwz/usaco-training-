/*
TASK:job
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAXM=35,MAXN=1005,INF=0x7fffffff;
int f[2][MAXM],t[2][MAXM],done[2][MAXN];
int n,m[2],maxt;

void greedily()
{
	int mint,loc;
	memset(f,0,sizeof(f));
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<2; ++j)
		{
			mint=INF;
			for(int k=0; k<m[j]; ++k)
				if(f[j][k]+t[j][k]<mint)
				{
					loc=k;
					mint=f[j][k]+t[j][k];
				}
			f[j][loc]=mint;
			done[j][i]=mint;
		}
	}
}

int main()
{
	freopen("job.in","r",stdin);
	freopen("job.out","w",stdout);
	scanf("%d %d %d",&n,&m[0],&m[1]);
	for(int i=0; i<m[0]; ++i)scanf("%d",&t[0][i]);
	for(int i=0; i<m[1]; ++i)scanf("%d",&t[1][i]);
	greedily();
	maxt=0;
	for(int i=0; i<m[0]; ++i)
		maxt=max(maxt,f[0][i]);
	printf("%d ",maxt);
	maxt=0;
	for(int i=0; i<n; ++i)
		maxt=max(maxt,done[1][i] + done[0][n-i-1]);
	printf("%d\n",maxt);
	//system("pause");
	return 0;
}
