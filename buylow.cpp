/*
TASK:buylow
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAXN = 5005, INF = 0X7FFFFFFF;

struct BigInt
{
	static const int MAXLEN = 500;
	short int num[MAXLEN];
	int len;

	BigInt()
	{
		memset(num, 0, sizeof(num));
		len=0;
	}
	
	BigInt operator = (int x)
	{
		len = 0;
		do{
			num[len++] = x % 10;
			x /= 10;
		}while (x);
		return *this;
	}

	BigInt operator + (const BigInt &b) const
	{
		BigInt c;
		c.len = max(len, b.len);
		for (int i = 0; i < c.len; ++i)
		{
			c.num[i] += num[i] + b.num[i];
			if (c.num[i] >= 10)
			{
				c.num[i+1] += 1;
				c.num[i] -= 10;
			}
		}
		if (c.num[c.len]) ++c.len;
		return c;
	}

}s[MAXN];
int f[MAXN], q[MAXN], h[MAXN*10];
int n;

int main()
{
	freopen("buylow.in", "r", stdin);
	freopen("buylow.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)scanf("%d", &q[i]);
	q[n] = -INF;
	f[0] = 1;
	s[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		int maxt = 0;
		s[i] = 1;
		for (int j = i - 1; j >= 0; --j)
			if (q[i] < q[j])
				if (f[j] > maxt)
				{
					maxt = f[j];
					memset(h, true, sizeof(h));
					h[q[j]] = false;
					s[i] = s[j];
				}
				else if (f[j] == maxt && h[q[j]])
					{
						h[q[j]] = false;
						s[i] = s[i] + s[j];
					}
		f[i] = maxt+1;
	}
	printf("%d ", f[n]-1);
	for (int i = s[n].len-1; i >= 0; --i) printf("%d", s[n].num[i]);
	printf("\n");
	//system("pause");
	return 0;
}
