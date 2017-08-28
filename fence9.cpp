/*
TASK:fence9
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
#define EPS 1e-10
int n,m,p,ans,lat;
int main()
{
	freopen("fence9.in","r",stdin);
	freopen("fence9.out","w",stdout);
	scanf("%d %d %d",&n,&m,&p);
	if(n<p && n!=0)ans=m-1;
	else ans=0;
	if(n)
	{
		lat=0;
		for(int i=1;i<n;++i)
		{
			while((double)m/n>(double)(lat+1)/i)++lat;
			ans+=lat;
		}
	}
	if(p-n>0)
	{
		lat=0;
		for(int i=p-1;i>n;--i)
		{
			while((double)-(lat+1)/(p-i)>(double)-m/(p-n))++lat;
			ans+=lat;
		}
	}
	if(p-n<0)
	{
		lat=0;
		for(int i=p+1;i<n;++i)
		{
			while((double)m/(n-p)>=(double)(lat+1)/(i-p))++lat;
			ans-=lat;
		}
	}
	printf("%d\n",ans);
	//system("pause");
	return 0;
}
