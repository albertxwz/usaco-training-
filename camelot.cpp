/*
ID:10179811
TASK:camelot
LANG:C++
#FILE
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct Drop
{
	int x,y;

	Drop(){}
	Drop(int x0,int y0):x(x0),y(y0){}

}Q[10000],king[100],knight[10000];

const int dking[2][8]={{0,-1,-1,-1,0,1,1,1},{-1,-1,0,1,1,1,0,-1}};
const int dknight[2][8]={{-2,-1,1,2,2,1,-1,-2},{1,2,2,1,-1,-2,-2,-1}};
int disking[45][30],disknight[45][30][45][30],kn1,kn2,h,t,r,c,ans;
bool flag[45][30];

int min(int a,int b){return a<b?a:b;}

bool test(int x,int y)
{
	if(x>0 && x<=r && y>0 && y<=c)return true;
	return false;
}

void bfs_king()
{
	memset(flag,true,sizeof(flag));
	memset(disking,0x3f,sizeof(disking));
	disking[king[0].x][king[0].y]=0;
	h=t=0;
	Q[t++]=king[0];
	while(h<t)
	{
		Drop now=Q[h++];
		for(int i=0;i<8;++i)
		{
			int tx=now.x+dking[0][i],ty=now.y+dking[1][i];
			if(test(tx,ty) && disking[tx][ty]>disking[now.x][now.y]+1)
			{
				disking[tx][ty]=disking[now.x][now.y]+1;
				if(flag[tx][ty])Q[t++]=Drop(tx,ty),flag[tx][ty]=false;
			}
		}
		flag[now.x][now.y]=true;
	}
}

void bfs(int x0,int y0)
{
	memset(disknight[x0][y0],0x3f,sizeof(disknight[x0][y0]));
	memset(flag,true,sizeof(flag));
	disknight[x0][y0][x0][y0]=0;
	flag[x0][y0]=false;
	h=t=0;
	Q[t++]=Drop(x0,y0);
	while(h<t)
	{
		Drop now=Q[h++];
		for(int i=0;i<8;++i)
		{
			int tx=now.x+dknight[0][i],ty=now.y+dknight[1][i];
			if(test(tx,ty) && disknight[x0][y0][tx][ty]>disknight[x0][y0][now.x][now.y]+1)
			{
				disknight[x0][y0][tx][ty]=disknight[x0][y0][now.x][now.y]+1;
				if(flag[tx][ty])Q[t++]=Drop(tx,ty),flag[tx][ty]=false;
			}
		}
		flag[now.x][now.y]=true;
	}
}

int main()
{
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	scanf("%d %d",&r,&c);
	kn1=kn2=0;
	char tmp[2];
	scanf("%s %d",tmp,&king[0].x);
	king[kn1++].y=tmp[0]-'A'+1;
	while(scanf("%s %d",tmp,&knight[kn2].x)==2)knight[kn2++].y=tmp[0]-'A'+1;
	if(kn2==0)
	{
		printf("0\n");
		return 0;
	}
	for(int i=-2;i<=2;++i)
		for(int j=-2;j<=2;++j)
			if((i!=0 || j!=0) && test(king[0].x+i,king[0].y+j))
				king[kn1++]=Drop(king[0].x+i,king[0].y+j);
	bfs_king();
	ans=0x7fffffff;
	for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
			bfs(i,j);
	for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
		{
			int step=0;
			for(int k=0;k<kn2;++k)step+=disknight[i][j][knight[k].x][knight[k].y];
			for(int k1=0;k1<kn1;++k1)
				for(int k2=0;k2<kn2;++k2)
				{
					if(disknight[i][j][knight[k2].x][knight[k2].y]>10000)continue;
					if(disknight[king[k1].x][king[k1].y][knight[k2].x][knight[k2].y]>10000)continue;
					if(disknight[i][j][king[k1].x][king[k1].y]>10000)continue;
					ans=min(ans,step-disknight[i][j][knight[k2].x][knight[k2].y]+disking[king[k1].x][king[k1].y]+disknight[king[k1].x][king[k1].y][knight[k2].x][knight[k2].y]+disknight[i][j][king[k1].x][king[k1].y]);
				}
		}
	printf("%d\n",ans);
	//system("pause");
	return 0;
}
