#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "chess.h"

int move_is_valid(piece p, player *opponent,char **board, move m, int *change_turn)
{
	if (p.type == 4)
		return (move_pony(board, p, opponent,m,change_turn));
	if (p.type == 3)
		return (move_bishop(p, opponent, board, m, change_turn));
	if (p.type == 2)
		return (move_rook(p, opponent, board, m, change_turn));
	if (p.type == 1)
		return (move_bishop(p, opponent, board, m, change_turn) || move_rook(p, opponent, board, m, change_turn));
	//if the piece is of type 5 => pawn
	if (*change_turn > 0)
	{
		if (p.type == 5)
			return (move_white_pawn(board, p,opponent, m, change_turn));
	}
	else
	{
		if (p.type == 5)
			return (move_black_pawn(board, p, opponent, m, change_turn));
	}
	return(0);
}


player update_piece(player ally, player *opponent, move m, char **board, int *change_turn)
{
	for (int i =0; i < ally.amount; i++)
	{
		//check wich piece we have to update
		if (ally.pieces[i].x == m.van.x && ally.pieces[i].y == m.van.y)
		{
			if (move_is_valid(ally.pieces[i], opponent, board, m, change_turn))
			{
				ally.pieces[i].x = m.naar.x;
				ally.pieces[i].y = m.naar.y;
				printf("piece huidige coord: x: %d  -  y: %d\n",ally.pieces[i].x, ally.pieces[i].y);
			}
			
		}
	}
	return (ally);
}



int main(int ac, char *ag[])
{
	
	char **board;
	player white;
	white.amount = 16;
	player black;
	black.amount = 16;
	move m;
	char input[4];
	int change_turns =1;
	
	//infinite while game loop
	white.pieces = init_white_pieces();
	black.pieces = init_black_pieces();
	board = update_board(white.pieces, black.pieces);
	print_board(board,white,black);
	
	while (1)
	{
		
		print_turn(change_turns);
		scanf("%s",input);
		printf("input %s\n",input);	
		m = parse_intput(input);
		//printf("van =>x: %d, y: %d  - naar=>x: %d, y: %d\n",m.van.x,m.van.y, m.naar.x,m.naar.y);
		if (input[0] == 'p')
		{	
			print_pieces(white.amount, white.pieces);
			print_pieces(black.amount, black.pieces);
		}
		if (change_turns > 0)
		{
			//WHITES TURN
			
			white = update_piece(white, &black,m, board,&change_turns);
			
		}
		else
		{	
			//BLACKSTURN
			
			black = update_piece(black, &white, m, board,&change_turns);
		}
		board = update_board(white.pieces,black.pieces);
		print_board(board, white, black);
		
	}
	return (0);	
	
}
