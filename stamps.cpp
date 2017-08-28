/*
ID:10179811
PROG:stamps
LANG:C++
#FILE
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int MAXC=2000005;
int f[MAXC],money[55],K,N,ans;

int min(int a,int b){return a<b?a:b;}

int main()
{
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	memset(f,0x7f,sizeof(f));
	f[0]=0;
	scanf("%d %d",&K,&N);
	for(int i=0;i<N;++i)scanf("%d",&money[i]);
	for(ans=1;ans<MAXC;++ans)
	{
		for(int i=0;i<N;++i)
			if(ans-money[i]>=0)
				f[ans]=min(f[ans],f[ans-money[i]]+1);
		if(f[ans]>K)break;
	}
	printf("%d\n",ans-1);
	//system("pause");
	return 0;
}
