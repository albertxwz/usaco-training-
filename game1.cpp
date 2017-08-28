/*
ID:10179811
TASK:game1
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int f[105][105],a[105],n,sum[105][105];

void solve(int l,int r)
{
	if(f[l][r])return;
	solve(l+1,r);
	solve(l,r-1);
	sum[l][r]=sum[l][r-1]+a[r];
	f[l][r]=sum[l][r]-min(f[l+1][r],f[l][r-1]);
}

int main()
{
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	memset(sum,0,sizeof(sum));
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		f[i][i]=sum[i][i]=a[i];
	}
	solve(0,n-1);
	printf("%d %d\n",f[0][n-1],sum[0][n-1]-f[0][n-1]);
	//system("pause");
	return 0;
}
