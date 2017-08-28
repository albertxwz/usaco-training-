/*
ID:10179811
TASK:ratios
LANG:C++
#FILE
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int INF=0x7fffffff;
int a[3],b[3],c[3],target[3],rea,reb,rec;

int main()
{
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	scanf("%d %d %d",&target[0],&target[1],&target[2]);
	scanf("%d %d %d",&a[0],&a[1],&a[2]);
	scanf("%d %d %d",&b[0],&b[1],&b[2]);
	scanf("%d %d %d",&c[0],&c[1],&c[2]);
	int mint=INF;
	for(int i=0;i<100;++i)
		for(int j=0;j<100;++j)
			for(int k=0;k<100;++k)
			{
				if(i==0 && j==0 && k==0)continue;
				bool flag=true;
				int d[3]={0,0,0};
				for(int l=0;l<3;++l)
					if((target[l]!=0 && (i*a[l]+j*b[l]+k*c[l])%target[l]) || (target[l]==0 && (i*a[l]+j*b[l]+k*c[l]!=0)))
					{
						flag=false;
						break;
					}
					else d[l]=target[l]?(i*a[l]+j*b[l]+k*c[l])/target[l]:-1;
				int maxt=0;
				for(int l=0;l<3;++l)maxt=maxt>d[l]?maxt:d[l];
				for(int l=0;l<3;++l)
					if(d[l]==-1)d[l]=maxt;
				if(flag && d[0]==d[1] && d[1]==d[2] && mint>d[0])
				{
					rea=i;
					reb=j;
					rec=k;
					mint=d[0];
				}
			}
	if(mint==INF)printf("NONE\n");
	else printf("%d %d %d %d\n",rea,reb,rec,mint);
	//system("pause");
	return 0;
}
