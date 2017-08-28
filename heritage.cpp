/*
ID:10179811
TASK:heritage
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

char pre[30],in[30];

void write(int L1,int R1,int L2,int R2)
{
	if(L1>R1 || L2>R2)return;
	int mid;
	for(int i=L1;i<=R1;++i)
		if(in[i]==pre[L2])
		{
			mid=i;
			break;
		}
	write(L1,mid-1,L2+1,R2-R1+mid);
	write(mid+1,R1,L2+mid-L1+1,R2);
	printf("%c",pre[L2]);
}

int main()
{
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	scanf("%s %s",in,pre);
	write(0,strlen(in)-1,0,strlen(pre)-1);
	printf("\n");
	//system("pause");
	return 0;
}
