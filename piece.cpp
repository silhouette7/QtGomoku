#include "piece.h"
#include <QPainter>

Piece::Piece(qreal x, qreal y)
{
    setPos(x, y);
}

QRectF Piece::boundingRect() const
{
    return QRectF(-PIECE_RADIUS, -PIECE_RADIUS, PIECE_RADIUS * 2, PIECE_RADIUS * 2);
}

QPainterPath Piece::shape() const
{
    QPainterPath p;
    p.addEllipse(QPointF(0, 0), PIECE_RADIUS, PIECE_RADIUS);
    return p;
}
