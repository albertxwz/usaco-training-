/*
ID:10179811
PROG:fact4
LANG:C++
#FILE
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int n,fact,len;

int main()
{
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	scanf("%d",&n);
	fact=1;
	for(int i=1;i<=n;++i)
	{
		fact*=i;
		while(fact%10==0)fact/=10;
		fact%=100000;
	}
	printf("%d\n",fact%10);
	//system("pause");
	return 0;
}
