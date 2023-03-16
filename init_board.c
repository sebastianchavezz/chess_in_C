#include "chess.h"


piece *init_black_pieces()
{
	//black
	piece *black_pieces = malloc(sizeof(piece) * 16);
	piece R1; R1.x = 0; R1.y = 0; R1.type = 2; R1.c = 'R';
	black_pieces[0] = R1;
	piece R2; R2.x = 7; R2.y = 0; R2.type = 2; R2.c = 'R';
	black_pieces[1] = R2;
	piece P1; P1.x = 1; P1.y = 0; P1.type = 4; P1.c = 'P';
	black_pieces[2] = P1;
	piece P2; P2.x = 6; P2.y = 0; P2.type = 4; P2.c = 'P';
	black_pieces[3] = P2;
	piece B1; B1.x = 2; B1.y = 0; B1.type = 3; B1.c = 'B';
	black_pieces[4] = B1 ;
	piece B2; B2.x = 5; B2.y = 0; B2.type = 3; B2.c = 'B';
	black_pieces[5] = B2;
	piece Q; Q.x = 3; Q.y = 0; Q.type = 1; Q.c = 'Q';
	black_pieces[6] = Q;
	piece K; K.x = 4; K.y = 0; K.type = 0; K.c = 'K';
	black_pieces[7] = K;
	piece z1; z1.x = 0; z1.y = 1; z1.type = 5; z1.c = 'z';
	black_pieces[8] = z1;
	piece z2; z2.x = 1; z2.y = 1; z2.type = 5; z2.c = 'z';
	black_pieces[9] = z2;
	piece z3; z3.x = 2; z3.y = 1; z3.type = 5; z3.c = 'z';
	black_pieces[10] = z3;
	piece z4; z4.x = 3; z4.y = 1; z4.type = 5; z4.c = 'z';
	black_pieces[11] = z4;
	piece z5; z5.x = 4; z5.y = 1; z5.type = 5; z5.c = 'z';
	black_pieces[12] = z5;
	piece z6; z6.x = 5; z6.y = 1; z6.type = 5; z6.c = 'z';
	black_pieces[13] = z6;
	piece z7; z7.x = 6; z7.y = 1; z7.type = 5; z7.c = 'z';
	black_pieces[14] = z7;
	piece z8; z8.x = 7; z8.y = 1; z8.type = 5; z8.c = 'z';
	black_pieces[15] = z8;

	
	return (black_pieces);
	

}

piece *init_white_pieces()
{
	//white
	piece *white_pieces = malloc(sizeof(piece) * 16);
	piece r1; r1.x = 0; r1.y = 7; r1.type = 2; r1.c = 'r';
	white_pieces[0] = r1;
	piece r2; r2.x = 7; r2.y = 7; r2.type = 2; r2.c = 'r';
	white_pieces[1] = r2;
	piece p1; p1.x = 1; p1.y = 7; p1.type = 4; p1.c = 'p';
	white_pieces[2] = p1;
	piece p2; p2.x = 6; p2.y = 7; p2.type = 4; p2.c = 'p';
	white_pieces[3] = p2;
	piece b1; b1.x = 2; b1.y = 7; b1.type = 3; b1.c = 'b';
	white_pieces[4] = b1;
	piece b2; b2.x = 5; b2.y = 7; b2.type = 3; b2.c = 'b';
	white_pieces[5] = b2;
	piece q; q.x = 3; q.y = 7; q.type = 1; q.c = 'q';
	white_pieces[6] = q;
	piece k; k.x = 4; k.y = 7; k.type = 0; k.c = 'k';
	white_pieces[7] = k;
	piece w1; w1.x = 0; w1.y = 6; w1.type = 5; w1.c = 'w';
	white_pieces[8] = w1;
	piece w2; w2.x = 1; w2.y = 6; w2.type = 5; w2.c = 'w';
	white_pieces[9] = w2;
	piece w3; w3.x = 2; w3.y = 6; w3.type = 5; w3.c = 'w';
	white_pieces[10] = w3;
	piece w4; w4.x = 3; w4.y = 6; w4.type = 5; w4.c = 'w';
	white_pieces[11] = w4;
	piece w5; w5.x = 4; w5.y = 6; w5.type = 5; w5.c = 'w';
	white_pieces[12] = w5;
	piece w6; w6.x = 5; w6.y = 6; w6.type = 5; w6.c = 'w';
	white_pieces[13] = w6;
	piece w7; w7.x = 6; w7.y = 6; w7.type = 5; w7.c = 'w';
	white_pieces[14] = w7;
	piece w8; w8.x = 7; w8.y = 6; w8.type = 5; w8.c = 'w';
	white_pieces[15] = w8;


	return (white_pieces);
}
