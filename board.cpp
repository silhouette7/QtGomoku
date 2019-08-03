#include "board.h"
#include "constants.h"
#include <QPainter>

Board::Board()
{
    setPos(0, 0);
}

QRectF Board::boundingRect() const
{
    return QRectF(-300, -300, 600, 600);
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    for(int i = 0; i <= 12; i++){
        painter->drawLine(-300, -300 + TILE_SIZE * i, 300, -300 + TILE_SIZE * i);
        painter->drawLine(-300 + TILE_SIZE * i, -300, -300 + TILE_SIZE * i, 300);
    }

    painter->restore();
}
