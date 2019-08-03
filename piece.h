#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsItem>
#include "constants.h"

class Piece : public QGraphicsItem
{
public:
    Piece(qreal x, qreal y);
    QRectF boundingRect() const;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QPainterPath shape() const;
};

#endif // PIECE_H
