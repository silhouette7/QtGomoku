#include "blackpiece.h"
#include <QPainter>

BlackPiece::BlackPiece(qreal x, qreal y) : Piece(x, y) 
{
    setData(PIECE_TYPE, BLACK_PIECE);
}
void BlackPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::black);

    painter->restore();
}
