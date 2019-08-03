#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsItem>

class Board : public QGraphicsItem
{
public:
    Board();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // BOARD_H
