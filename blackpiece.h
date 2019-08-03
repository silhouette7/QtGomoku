#ifndef BLACKPIECE_H
#define BLACKPIECE_H

#include "piece.h"

class BlackPiece : public Piece
{
public:
    BlackPiece(qreal x, qreal y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // BLACKPIECE_H
