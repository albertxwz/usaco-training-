/*
TASK:rockers
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,t,m,ans,a[25];

void dfs(int song,int disk,int time,int tot)
{
	ans=tot>ans?tot:ans;
	if(song==n)return;
	if(ans>tot+n-song-1)return;
	if(a[song]<=time)dfs(song+1,disk,time-a[song],tot+1);
	else if(a[song]<=t && disk+1<m)dfs(song+1,disk+1,t-a[song],tot+1);
	dfs(song+1,disk,time,tot);
}

int main()
{
	freopen("rockers.in","r",stdin);
	freopen("rockers.out","w",stdout);
	scanf("%d %d %d",&n,&t,&m);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	ans=0;
	dfs(0,0,t,0);
	printf("%d\n",ans);
	//system("pause");
	return 0;
}
