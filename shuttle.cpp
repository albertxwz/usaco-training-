/*
TASK:shuttle
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int n, cnt;

int main()
{
	freopen("shuttle.in", "r", stdin);
	freopen("shuttle.out", "w", stdout);
	scanf("%d", &n);
	int space = n + n % 2;
	cnt = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= i; ++j)
		{
			if (i % 2)
			{
				if (space % 2) space += 2;
				else space -= 1;
			}
			else
				if (space % 2) space += 1;
				else space -= 2;
			printf("%d", space + !(n % 2));
			++cnt;
			if (cnt % 20 == 0) printf("\n");
			else printf(" ");
		}
	for (int i = n - 1; i > 0; --i)
		for (int j = 0; j <= i; ++j)
		{
			if (i % 2)
			{
				if (space % 2) space += 2;
				else space += 1;
			}
			else
				if (space % 2) space -= 1;
				else space -=2;
			printf("%d", space + !(n % 2));
			++cnt;
			if (cnt % 20 == 0) printf("\n");
			else printf(" ");
		}	
		printf("%d\n", n + 1);
		//system("pause");
		return 0;
}
