#include "chess.h"

void print_turn(int turn)
{
	if (turn > 0)
	{
		printf("WHITE TURN\n");
	}
	else
	{
		printf("BLACK TURN\n");
	}
}

char **update_board(piece *white_pieces, piece *black_pieces)
{
	char **chessboard = malloc(sizeof(char *) * S);
	for (int i = 0; i < S; i++)
	{
		chessboard[i] = malloc(sizeof(char) * S);
		for (int j = 0; j < S; j++)
		{
			chessboard[i][j] = '-';
		}
	}
	int i;
	i = 0;
	while (i < 2*S)
	{
		chessboard[white_pieces[i].y][white_pieces[i].x] = white_pieces[i].c;
		chessboard[black_pieces[i].y][black_pieces[i].x] = black_pieces[i].c;
		i++;
	}
	return (chessboard);
}

void print_board(char **board, player white, player black)
{
	int i;
	int j;
	char y = '8';
	char x = 'a';

	system("clear");
	
	print_pieces(black.amount, black.pieces);
	write(1,"\n",1);
	write(1,"\n",1);
	i = 0;
	while (i < S)
	{
		j = 0;
		write(1,&y,1);
		write(1,"|   ",4);
		while (j < S)
		{
			write(1,&board[i][j],1);
			write(1,"  ",2);
			j++;
		}
		write(1,"\n",1);
		y--;
		i++;
	}
	write(1,"  __________________________\n",28);
	write(1,"\n",1);
	write(1,"     a  b  c  d  e  f  g  h",27);
	write(1,"\n",1);
	write(1,"\n",1);
	print_pieces(white.amount, white.pieces);
	
}