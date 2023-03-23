#include "chess.h"

//brute force all the possible moves of the enemies.
//return 1 if the attack the king => if king in check
int king_attacked(char **board, piece king, player *opponent)
{
    for (int i =0; i< opponent->amount; i++)
    {
        if (opponent->pieces[i].type == 3)
        {
            return (bishop_checked_king(board, opponent->pieces[i], king));    
        }
        if (opponent->pieces[i].type == 2)
        {
            return (rook_checked_king(board, opponent->pieces[i], king));    
        }
    }
    return (0);
}

int move_king(char **board, piece p, player *opponent, move m, int *change_turn)
{
    if ((p.x + 1 == m.naar.x)||(p.x - 1 == m.naar.x)\
    ||(p.y + 1 == m.naar.y)||(p.y - 1 == m.naar.y) && board[m.naar.y][m.naar.x] == '-')
    {
        //nedds to check if the move is valid, e.g. its not in check
        *change_turn *= -1;
        return (1);
    }
    //check if king is in check by checking all the possibles moves of the enemies

    return (0);
}
