/*
ID:10179811
PROG:contact
LANG:C++
#FILE
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct Sq
{
	int ID,p;
	bool operator < (const Sq &b)const{return p>b.p||(p==b.p&&ID<b.ID);}
};

const int MAXNODE=50000;
int a,b,n,lens=0,s[2000005];
Sq ans[MAXNODE];

void change(int l,int r)
{
	int number=1;
	for(int i=l;i<r;++i)number=(number<<1)+s[i];
	ans[number].ID=number;
	++ans[number].p;
}

void print(int p)
{
	int er[13],lenp=0;
	while(p)
	{
		er[lenp++]=p%2;
		p/=2;
	}
	for(int i=lenp-2;i>=0;--i)printf("%d",er[i]);
}

int main()
{
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);
	for(int i=0;i<MAXNODE;++i)ans[i].p=0;
	scanf("%d %d %d",&a,&b,&n);
	char txt[100];
	while(scanf("%s",txt)==1)
	{
		for(int i=0;i<strlen(txt);++i)
		{
			s[lens++]=txt[i]-'0';
			for(int j=max(0,lens-b);j<=max(0,lens-a);++j)
				change(j,lens);
		}
	}
	sort(ans,ans+MAXNODE);
	int i=0;
	while(n--)
	{
		if(ans[i].p&&ans[i].ID>=(1<<a))
		{
			printf("%d\n",ans[i].p);
			int tmp=0;
			for(int j=i;j<MAXNODE;++j)
				if(ans[j].p==ans[i].p)
				{
					print(ans[j].ID);
					++tmp;
					if(ans[j+1].p==ans[i].p)
						if(tmp%6==0)printf("\n");
						else printf(" ");
					i=j;
				}
				else break;
			printf("\n");
			++i;
		}
		else break;
	}
	//system("pause");
	return 0;
}
