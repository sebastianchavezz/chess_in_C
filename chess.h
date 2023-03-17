#ifndef chess
# define chess
#define S 8
#define IN 4

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
typedef struct t_piece
{
	int x;
	int y;
	int type;
	char c;

} piece;

typedef struct t_plaey
{
	piece *pieces;
	int amount;
} player;



typedef struct t_van
{
	int x;
	int y;

}van;

typedef struct t_naar
{
	int x;
	int y;
}naar;

typedef struct t_move
{
	van van;
	naar naar;
}move;

int move_is_valid(piece p, player *opponent,char **board, move m, int *change_turn);
player update_piece(player ally, player *opponent, move m, char **board, int *change_turn);
int move_bishop(piece p, player *opponent, char **board, move m, int *change_turn);
void print_turn(int turn);
char **update_board(piece *white_pieces, piece *black_pieces);
void print_board(char **board, player white, player black);
piece *init_black_pieces();
piece *init_white_pieces();
int move_black_pawn(char **board, piece p, player *opponent ,move m, int *change_turn);
int move_white_pawn(char **board, piece p, player *opponent, move m, int *change_turn);
int move_pony(char **board, piece p, player *opponent, move m, int *change_turn);
int move_rook(piece p, player *opponent, char **board, move m, int *change_turn);
int abs(int get);
int richting(int get);
int max(int a, int b);
move parse_intput(char *str);
void print_pieces(int s, piece *p);
int move_king(char **board, piece p, player *opponent, move m, int *change_turn);
#endif