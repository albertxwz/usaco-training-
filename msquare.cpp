/*
ID:10179811
TASK:msquare
LANG:C++
#FILE
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct Seq
{
	int a[2][4],step,fa;
	char cmd;
}Q[50000],seq;

const int MOD=99991;
int h,t,target[2][4],cnt,hash[100000];

void print(int x)
{
	if(x!=0)print(Q[x].fa);
	else return;
	if(cnt%60==0)printf("\n");
	++cnt;
	printf("%c",Q[x].cmd);
}

bool check()
{
	int x=seq.a[0][0]*100000000+seq.a[0][1]*10000000+seq.a[0][2]*1000000+seq.a[0][3]*100000+seq.a[1][3]*10000+seq.a[1][2]*1000+seq.a[1][2]*100+seq.a[1][1]*10+seq.a[1][0];
	int o;
	for(o=x%MOD;hash[o]!=0&&hash[o]!=x;o=(o+1)%MOD);
	if(hash[o])return false;
	else
	{
		hash[o]=x;
		return true;
	}
}

bool judge()
{
	for(int i=0;i<2;++i)
		for(int j=0;j<4;++j)
			if(seq.a[i][j]!=target[i][j])return false;
	return true;
}

void BFS()
{
	t=1;
	while(h<t)
	{
		for(int i=0;i<4;++i)
		{
			seq.a[0][i]=Q[h].a[1][i];
			seq.a[1][i]=Q[h].a[0][i];
		}
		seq.step=Q[h].step+1;
		seq.fa=h;
		seq.cmd='A';
		if(check())
		{
			Q[t++]=seq;
			if(judge())
			{
				printf("%d",seq.step);
				print(t-1);
				printf("\n");
				return;
			}
		}
		for(int i=1;i<4;++i)
		{
			seq.a[0][i]=Q[h].a[0][i-1];
			seq.a[1][i]=Q[h].a[1][i-1];
		}
		seq.a[0][0]=Q[h].a[0][3];
		seq.a[1][0]=Q[h].a[1][3];
		seq.step=Q[h].step+1;
		seq.fa=h;
		seq.cmd='B';
		if(check())
		{
			Q[t++]=seq;
			if(judge())
			{
				printf("%d",seq.step);
				print(t-1);
				printf("\n");
				return;
			}
		}
		seq=Q[h];
		seq.a[0][2]=Q[h].a[0][1];
		seq.a[0][1]=Q[h].a[1][1];
		seq.a[1][2]=Q[h].a[0][2];
		seq.a[1][1]=Q[h].a[1][2];
		seq.step=Q[h].step+1;
		seq.fa=h;
		seq.cmd='C';
		if(check())
		{
			Q[t++]=seq;
			if(judge())
			{
				printf("%d",seq.step);
				print(t-1);
				printf("\n");
				return;
			}
		}
		++h;
	}
}

int main()
{
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	h=t=0;
	for(int i=1;i<=4;++i)
	{
		scanf("%d",&target[0][i-1]);
		Q[0].a[0][i-1]=i;
	}
	for(int i=5;i<=8;++i)
	{
		scanf("%d",&target[1][8-i]);
		Q[0].a[1][8-i]=i;
	}
	Q[0].step=Q[0].fa=0;
	cnt=0;
	seq=Q[0];
	memset(hash,0,sizeof(hash));
	if(judge())printf("0\n\n");
	else BFS();
	//system("pause");
	return 0;
}
