#include "chess.h"

int black_pawn_king_checked(piece p, piece king)
{
	//te doen staat ook de 2stappen naar voor pawn te checken
	if ((p.x + 1 == king.x && p.y + 1 == king.y) || (p.x - 1 == king.x && p.y + 1 == king.y))
	{
		return (1);
	}
	return (0);
}
int white_pawn_king_checked(piece p, piece king)
{
	if ((p.x + 1 == king.x && p.y - 1 == king.y) || (p.x - 1 == king.x && p.y - 1 == king.y))
	{
		return (1);
	}
	return (0);
}



int move_black_pawn(char **board, piece p, player *opponent ,move m, int *change_turn)
{
	//if pawn at begin Y, can move 2 places
	//check for 
	if (p.y == 1 && p.y + 2 == m.naar.y && p.x == m.naar.x && board[m.naar.y][p.x] == '-')
	{
		*change_turn *= -1;
		return (1);
	}
	//if the place infront of the pawn is free, its a valid space, then change the turn
	if (p.y + 1 == m.naar.y && p.x == m.naar.x &&board[m.naar.y][p.x] == '-')
	{
		*change_turn *= -1;
		return (1);
	}
	if ((p.x + 1 == m.naar.x && p.y + 1 == m.naar.y) || (p.x - 1 == m.naar.x && p.y + 1 == m.naar.y))
	{
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
	}
	return (0);
}

int move_white_pawn(char **board, piece p, player *opponent, move m, int *change_turn)
{
	
	//if pawn at begin Y, can move 2 places
	if (p.y == 6 && p.y - 2 == m.naar.y && p.x == m.naar.x &&board[m.naar.y][p.x] == '-')
	{
		*change_turn *= -1;
		return (1);
	}
	//if the place infront of the pawn is free, its a valid space, then change the turn
	if (p.y - 1 == m.naar.y && p.x == m.naar.x &&board[m.naar.y][p.x] == '-')
	{
		*change_turn *= -1;
		return (1);
	}
	//check if captured a opponents piece
	if ((p.x + 1 == m.naar.x && p.y - 1 == m.naar.y) || (p.x - 1 == m.naar.x && p.y - 1 == m.naar.y))
	{
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
	}
	return (0);
}