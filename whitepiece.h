#ifndef WHITEPIECE_H
#define WHITEPIECE_H

#include "piece.h"

class WhitePiece : public Piece
{
public:
    WhitePiece(qreal x, qreal y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // WHITEPIECE_H
