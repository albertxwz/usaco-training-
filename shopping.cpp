/*
ID:10179811
TASK:shopping
LANG:C++
#FILE
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int s,offer[200][5][2],p[200],target[5][2],f[6][6][6][6][6];

int find(int w,int id)
{
	for(int i=0;i<5;++i)
		if(target[id][0]==offer[w][i][0] || offer[w][i][0]==0)return i;
	return -1;
}

int min(int a,int b){return a<b?a:b;}

int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	memset(offer,0,sizeof(offer));
	scanf("%d",&s);
	for(int i=0;i<s;++i)
	{
		int n;
		scanf("%d",&n);
		for(int j=0;j<n;++j)scanf("%d %d",&offer[i][j][0],&offer[i][j][1]);
		scanf("%d",&p[i]);
	}
	memset(target,0,sizeof(target));
	int b;
	scanf("%d",&b);
	for(int i=s;i<s+b;++i)
	{
		scanf("%d %d %d",&target[i-s][0],&target[i-s][1],&p[i]);
		offer[i][0][0]=target[i-s][0];
		offer[i][0][1]=1;
	}
	memset(f,0x7f,sizeof(f));
	f[0][0][0][0][0]=0;
	for(int a0=0;a0<=target[0][1];++a0)
		for(int a1=0;a1<=target[1][1];++a1)
			for(int a2=0;a2<=target[2][1];++a2)
				for(int a3=0;a3<=target[3][1];++a3)
					for(int a4=0;a4<=target[4][1];++a4)
						for(int i=0;i<s+b;++i)
						{
							int loc[5];
							bool flag=true;
							for(int j=0;j<5;++j)
								if(find(i,j)==-1)
								{flag=false; break;}
								else loc[j]=find(i,j);
							if(!flag)continue;
							if(a0>=offer[i][loc[0]][1] && a1>=offer[i][loc[1]][1] && a2>=offer[i][loc[2]][1] && a3>=offer[i][loc[3]][1] && a4>=offer[i][loc[4]][1])
								f[a0][a1][a2][a3][a4]=min(f[a0][a1][a2][a3][a4],f[a0-offer[i][loc[0]][1]][a1-offer[i][loc[1]][1]][a2-offer[i][loc[2]][1]][a3-offer[i][loc[3]][1]][a4-offer[i][loc[4]][1]]+p[i]);
						}
	printf("%d\n",f[target[0][1]][target[1][1]][target[2][1]][target[3][1]][target[4][1]]);
	//system("pause");
	return 0;
}
