/*
TASK:window
LANG:C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node
{
	char dat;
	double x0, y0, x1, y1;
	Node *next;
}*head, *tail, *p;

void ins_back(Node *&now)
{
	if (head == NULL) head = tail = now;
	else
	{
		tail->next = now;
		tail = now;
	}
}

void ins_front(Node *&now)
{
	now->next = head;
	head = now;
}

Node *find(char x)
{
	for (Node *it = head; it != NULL; it = it->next)
		if (it->dat == x) return it;
	return NULL;
}

double cbs(Node *&now, double x0, double y0, double x1, double y1)
{
	if (x0 >= x1 || y0 >= y1) return 0;
	if (now == NULL) return (x1 - x0) * (y1 - y0);
	return cbs(now->next, x0, y0, min(x1, now->x0), y1)
			+ cbs(now->next, max(x0, now->x0), y0, min(x1, now->x1), min(y1, now->y0))
			+ cbs(now->next, max(x0, now->x0), max(y0, now->y1), min(x1, now->x1), y1)
			+ cbs(now->next, max(x0, now->x1), y0, x1, y1);
}

int main()
{
	freopen("window.in", "r", stdin);
	freopen("window.out", "w", stdout);
	char cmd[100];
	while (scanf("%s", cmd) == 1)
	{
		if (cmd[0] == 'w')
		{
			p = new Node;
			sscanf(cmd, "%*c%*c%c,%lf,%lf,%lf,%lf", &p->dat, &p->x0, &p->y0, &p->x1, &p->y1);
			if (p->x0 > p->x1) swap(p->x0, p->x1);
			if (p->y0 > p->y1) swap(p->y0, p->y1);
			p->next = NULL;
			ins_back(p);
		}
		else
		{
			char x;
			sscanf(cmd, "%*c%*c%c", &x);
			
			if (cmd[0] == 't')
			{
				if (head == NULL || head == tail) continue;
				if (head->dat == x)
				{
					p = head;
					head = head->next;
					p->next = NULL;
					ins_back(p);
				}
				else
					for (Node *it = head; it->next != tail; it = it->next)
						if (it->next->dat == x)
						{
							p = it->next;
							it->next = p->next;
							p->next = NULL;
							ins_back(p);
							break;
						}
			}
			
			if (cmd[0] == 'b')
			{
				if (head == NULL) continue;
				for (Node *it = head; it->next != NULL; it = it->next)
					if (it->next->dat == x)
					{
						if (it->next == tail)
						{
							p = tail;
							it->next = NULL;
							tail = it;
							ins_front(p);
						}
						else
						{
							p = it->next;
							it->next = p->next;
							p->next = NULL;
							ins_front(p);
						}
						break;
					}
			}
			
			if (cmd[0] == 'd')
			{
				if (head == NULL) continue;
				if (head->dat == x)
				{
					p = head;
					head = head->next;
					p->next = NULL;
					delete p;
				}
				else
					for (Node *it = head; it->next != NULL; it = it->next)
						if (it->next->dat == x)
						{
							if (it->next == tail)
							{
								p = tail;
								tail = it;
								tail->next = NULL;
							}
							else
							{
								p = it->next;
								it->next = p->next;
							}
							p->next = NULL;
							delete p;
							break;
						}
			}
			
			if (cmd[0] == 's')
			{
				p = find(x);
				if (p == NULL) printf("0.000\n");
				else printf("%.3lf\n", 100.0 * cbs(p->next, p->x0, p->y0, p->x1, p->y1) / (p->x1 - p->x0) / (p->y1 - p->y0));
			}
		}
	}
	return 0;
}
