/*
ID:10179811
PROG:kimbits
LANG:C++
#FILE
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

long long m,l;
bool ans[35];

int C(int n,int k)
{
	long long sum=1;
	for(int i=1;i<=k;++i)sum=sum*(n-i+1)/i;
	return sum;
}

void dfs(int n)
{
	--m;
	if(m==0)return;
	for(int i=1;i<n;++i)
	{
		long long tot=0;
		for(int j=0;j<i&&j<l;++j)tot+=C(i-1,j);
		if(tot>=m)
		{
			ans[i]=true;
			--l;
			dfs(i);
			return;
		}
		else m-=tot;
	}
}

int main()
{
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	int n;
	cin>>n>>l>>m;
	memset(ans,false,sizeof(ans));
	dfs(n+1);
	for(int i=n;i>=1;--i)
		if(ans[i])printf("1");
		else printf("0");
	printf("\n");
	//system("pause");
	return 0;
}
