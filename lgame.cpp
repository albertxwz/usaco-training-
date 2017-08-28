/*
TASK:lgame
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<algorithm>
using namespace std;

const int value[26] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
int ch[26], score[40005], cnt[40005][26];
int lens, maxt, tot, anslen;
char s[10], dict[40000][10], best[40000][10];
FILE *fin1, *fin2, *fout;

int main()
{
	/*open file*/
	fin1 = fopen("lgame.in", "rb");
	fin2 = fopen("lgame.dict", "rb");
	fout = fopen("lgame.out", "wb");
	
	/*input*/
	memset(ch, 0, sizeof(ch));
	fscanf(fin1, "%s", s);
	for (int i = 0; i < (lens = strlen(s)); ++i)
		ch[s[i] - 'a']++;
	tot = 0;
	while (fscanf(fin2, "%s", dict[tot]), dict[tot][0] != '.')
	{
		score[tot] = 0;
		memset(cnt[tot], 0, sizeof(cnt[tot]));
		for (int i = 0; i < strlen(dict[tot]); ++i)
		{
			score[tot] += value[dict[tot][i] - 'a'];
			cnt[tot][dict[tot][i] - 'a']++;
		}
		bool flag = true;
		for (int i = 0; i < 26; ++i)
			if (cnt[tot][i] > ch[i])
			{
				flag = false;
				break;
			}
		if (flag) tot++;
	}

	/*work*/
	anslen = 0;
	maxt = -1;
	memset(s, 0, sizeof(s));
	for (int i = 0; i < tot; ++i)
	{
		if (score[i] >= maxt)
		{
			if (score[i] > maxt) anslen = 0;
			maxt = score[i];
			memcpy(best[anslen], dict[i], sizeof(dict[i]));
			anslen++;
		}
		int len = strlen(dict[i]);
		for (int j = i + 1; j < tot; ++j)
		{
			if (strlen(dict[j]) + len > lens) continue;
			bool flag = true;
			for (int k = 0; k < 26; ++k)
				if (ch[k] < cnt[i][k] + cnt[j][k])
				{
					flag = false;
					break;
				}
			if (flag && score[i] + score[j] >= maxt)
			{
				if (score[i] + score[j] > maxt) anslen = 0;
				maxt = score[i] + score[j];
				memcpy(best[anslen], dict[i], sizeof(dict[i]));
				best[anslen][len] = ' ';
				memcpy(best[anslen] + len + 1, dict[j], sizeof(dict[j]));
				anslen++;
			}
		}
	}
	
	/*ouput*/
	fprintf(fout, "%d\n", maxt);
	for (int i = 0; i < anslen; ++i)
		fprintf(fout, "%s\n", best[i]);

	/*close file*/
	fclose(fin1);
	fclose(fin2);
	fclose(fout);
	return 0;
}
