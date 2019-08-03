#include "whitepiece.h"
#include <QPainter>

WhitePiece::WhitePiece(qreal x, qreal y) : Piece(x, y) {
    setData(PIECE_TYPE, WHITE_PIECE);
}
void WhitePiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::white);
    painter->drawPath(shape());

    painter->restore();
}
