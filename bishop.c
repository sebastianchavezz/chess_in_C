#include "chess.h"

int move_bishop(piece p, player *opponent, char **board, move m, int *change_turn)
{
	
	//this passes all the allies
	if (abs(p.x - m.naar.x) == abs(p.y - m.naar.y))
	{	
		int r_x = richting(m.naar.x - p.x);
		int r_y = richting(m.naar.y - p.y);
		//check voor obstakels
		for (int i = 1; i < abs(p.x - m.naar.x); i++)
		{
			if (board[p.y+r_y*i][p.x+r_x*i] != '.')
			{
				printf("WE IN HERE %d\n",r_x);
				return (0);
			}
			printf("dx: %d  - dy: %d\n",r_x*i, r_y*i);
			
		}
		//check for every opponent if they are attacked
		for (int i = 0; i< opponent->amount; i++)
		{
			if (m.naar.x == opponent->pieces[i].x && m.naar.y == opponent->pieces[i].y)
			{
				for (int j = i + 1; j < opponent->amount; j++)
				{
					opponent->pieces[j - 1] = opponent->pieces[j];
				}
				opponent->amount--;
				print_pieces(opponent->amount,opponent->pieces);
				*change_turn *= -1;
				return (1);
			}
		}
		if (board[m.naar.y][m.naar.x] == '.')
		{
			*change_turn *= -1;
			return (1);
		}
	}
	return (0);
}