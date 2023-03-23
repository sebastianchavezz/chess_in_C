#include "chess.h"


int rook_checked_king(char **board, piece rook, piece king)
{
	if ((rook.x == king.x && rook.y != king.y) || (rook.x != king.x && rook.y == king.y))
	{
		//kon vervangen worden door in de for loop te checke als empty of king.char!
		if ((abs(rook.x - king.x) == 1 && rook.y == king.y)||(abs(rook.y - king.y) == 1 && rook.x == king.x))
		{
			return (1);
		}
		int r_x = richting(king.x - rook.x);
		int r_y = richting(king.y - rook.y);
		//check voor obstakels; miss splitten per richting zoals bij de king_attacked()
		for (int i = 1; i < max(abs(rook.x - king.x),abs(rook.y - king.y)) ; i++)
		{
			if (board[rook.y+r_y*i][rook.x+r_x*i] != '-')
			{
				
				return (0);
			}
		}
		return(1);
	}
	return (0);
}

int move_rook(piece p, player *opponent, char **board, move m, int *change_turn)
{
	if ((p.x == m.naar.x && p.y != m.naar.y) || (p.x != m.naar.x && p.y == m.naar.y))
	{
		int r_x = richting(m.naar.x - p.x);
		int r_y = richting(m.naar.y - p.y);
		//check voor obstakels; miss splitten per richting zoals bij de king_attacked()
		for (int i = 1; i < max(abs(p.x - m.naar.x),abs(p.y - m.naar.y)) ; i++)
		{
			if (board[p.y+r_y*i][p.x+r_x*i] != '-')
			{
				
				return (0);
			}
		}
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
		if (board[m.naar.y][m.naar.x] == '-')
		{
			*change_turn *= -1;
			return (1);
		}
	}
	return (0);
}