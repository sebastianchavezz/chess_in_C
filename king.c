#include "chess.h"

int move_king(char **board, piece p, player *opponent, move m, int *change_turn)
{
    if ((p.x + 1 == m.naar.x)||(p.x - 1 == m.naar.x)\
    ||(p.y + 1 == m.naar.y)||(p.y - 1 == m.naar.y) && board[m.naar.y][m.naar.x] == '-')
    {
        //nedds to check if the move is valid, e.g. its not in check
        *change_turn *= -1;
        return (1);
    }
    return (0);
}
