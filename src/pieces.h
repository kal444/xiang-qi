#ifndef PIECES_H
#define PIECES_H

#define H_NPOS  9
#define V_NPOS 10

struct _XQPiece;
typedef struct _XQPiece XQPiece;

struct _XQPiece
{
    char   *name;       /* a name like rook, or chariot */
    char ab_name;       /* a single letter designation */
};

XQPiece *current_ppos[V_POS][H_POS];

#endif /* PIECES_H */
