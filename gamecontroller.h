#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QMouseEvent>
#include "constants.h"

class Board;
class Piece;

class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(QGraphicsScene *scene, QObject *parent = nullptr);
    void start();
    void gameOver();
protected:
    bool eventFilter(QObject *watched, QEvent *event);
private:
    void mousePress(QGraphicsSceneMouseEvent *event);
    void judge(int x, int y, QVariant type);
    QGraphicsScene *scene;
    Board *board;
    Piece *curPiece;
    int flag;

signals:
    void win(const QString &name);

public slots:
};

#endif // GAMECONTROLLER_H
