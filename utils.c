#include "chess.h"

int abs(int get)
{
	if (get < 0)
	{
		return (get * -1);
	}
	return (get);
}

int richting(int get)
{
	if (get < 0)
	{
		return (-1);
	}
	else if (get > 0)
	{
		return (1);
	}
	return 0;
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
void print_pieces(int s, piece *p)
{
	for (int i = 0; i < s; i++)
	{
		printf("%c ",p[i].c);
	}
	printf("\n");
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;

}

move parse_intput(char *str)
{
	move m;
	van v;
	naar n;
	
	v.x = str[0] - 'a';
	v.y = '8' - str[1];
	n.x = str[2] - 'a';
	n.y = '8' - str[3];
	m.van = v;
	m.naar = n;
	return (m);	
}