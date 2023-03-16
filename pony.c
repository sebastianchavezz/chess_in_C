#include "chess.h"

int move_pony(char **board, piece p, player *opponent, move m, int *change_turn)
{
	//pony can move in L 
	//right move for pony
	if ((p.y -2 == m.naar.y && p.x +1 == m.naar.x)||(p.y -2 == m.naar.y && p.x -1 == m.naar.x)||\
		(p.y +2 == m.naar.y && p.x +1 == m.naar.x)||(p.y +2 == m.naar.y && p.x -1 == m.naar.x)\
		||(p.y +1 == m.naar.y && p.x +2 == m.naar.x)||(p.y -1 == m.naar.y && p.x +2 == m.naar.x )||\
		(p.y +1 == m.naar.y && p.x -2 == m.naar.x )||(p.y -1 == m.naar.y && p.x -2 == m.naar.x ))
	{
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
		if(board[m.naar.y][m.naar.x] == '.')
		{
			*change_turn *= -1;
			return (1);
		}
	}
	return (0);
}
