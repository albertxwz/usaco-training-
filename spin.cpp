/*
ID:10179811
TASK:spin
LANG:C++
#FILE
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int N=5,round=360;
struct Lun
{
	int rotate,q,ws[6],ww[6];
}lun[5];

int cnt[round];

bool check()
{
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<N;++i)
		for(int j=0;j<lun[i].q;++j)
			for(int k=0;k<=lun[i].ww[j];++k)
				++cnt[(lun[i].ws[j]+k)%round];
	for(int i=0;i<round;++i)
		if(cnt[i]==5)return true;
	return false;
}

int main()
{
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	for(int i=0;i<N;++i)
	{
		scanf("%d %d",&lun[i].rotate,&lun[i].q);
		for(int j=0;j<lun[i].q;++j)scanf("%d %d",&lun[i].ws[j],&lun[i].ww[j]);
	}
	int ans;
	for(ans=0;ans<=round;++ans)
	{
		if(check())
		{
			printf("%d\n",ans);
			//system("pause");
			return 0;
		}
		for(int j=0;j<N;++j)
			for(int k=0;k<lun[j].q;++k)
			{
				lun[j].ws[k]+=lun[j].rotate;
				while(lun[j].ws[k]>=round)lun[j].ws[k]-=round;
			}
	}
	printf("none\n");
	//system("pause");
	return 0;
}
