/*
TASK:nuggets
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int MAXN=70000;
bool f[MAXN];
int n,a[15];

int find()
{
	for(int i=MAXN-1;i>0;--i)
		if(!f[i])
			if(i>65024)return 0;
			else return i;
	return 0;
}

int main()
{
	freopen("nuggets.in","r",stdin);
	freopen("nuggets.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	memset(f,false,sizeof(f));
	f[0]=true;
	for(int i=0;i<n;++i)
		for(int j=1;j<MAXN;++j)
			if(j>=a[i])f[j]=f[j] || f[j-a[i]];
	printf("%d\n",find());
	//system("pause");
	return 0;
}
