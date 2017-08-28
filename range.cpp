/*
ID:10179811
TASK:range
LANG:C++
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int MAXN=255;
int n,cnt[MAXN];
bool f[MAXN][MAXN],g[2][MAXN][MAXN];
char s[MAXN];

int main()
{
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	scanf("%d",&n);
	memset(f,false,sizeof(f));
	for(int i=0;i<n;++i)
	{
		scanf("%s",s);
		for(int j=0;j<n;++j)
			if(s[j]=='1')f[i][j]=true;
			else f[i][j]=false;
	}
	int cur=0;
	memcpy(g[cur],f,sizeof(f));
	memset(g[cur^1],false,sizeof(g[cur^1]));
	memset(cnt,0,sizeof(cnt));
	for(int k=2;k<=n;++k)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				if(i-k+1>=0 && j-k+1>=0)
					g[cur^1][i][j]=g[cur][i][j-1] && g[cur][i-1][j] && f[i-k+1][j-k+1] && f[i][j];
				if(g[cur^1][i][j])++cnt[k];
			}
		memset(g[cur],false,sizeof(g[cur]));
		cur^=1;
	}
	for(int i=2;i<=n;++i)
		if(cnt[i])printf("%d %d\n",i,cnt[i]);
	//system("pause");
	return 0;
}
