#include "gamecontroller.h"
#include "board.h"
#include "blackpiece.h"
#include "whitepiece.h"
#include <QEvent>
#include <QtDebug>
#include <QGraphicsSceneEvent>

GameController::GameController(QGraphicsScene *scene, QObject *parent)
    : QObject(parent),
      scene(scene),
      board(new Board())
{
    scene->addItem(board);
    flag = 0;
}

void GameController::start()
{
    gameOver();
    qDebug() << "start a new game";
    scene->installEventFilter(this);
}

void GameController::gameOver()
{
    scene->clear();
    board = new Board();
    scene->addItem(board);
    flag = 0;
}

bool GameController::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress){
        mousePress(static_cast<QGraphicsSceneMouseEvent *>(event));
        return true;
    }
    else return QObject::eventFilter(watched, event);
}

void GameController::mousePress(QGraphicsSceneMouseEvent *event)
{
    QPointF curMouse = event->scenePos();
    int p[] = {static_cast<int>(curMouse.x()), static_cast<int>(curMouse.y())};
    for(int &x : p){
        if(x >= 0){
            if(x % TILE_SIZE <= TILE_SIZE / 3) x = (x / TILE_SIZE) * TILE_SIZE;
            else if(x % TILE_SIZE >= 2 * TILE_SIZE / 3) x = (x / TILE_SIZE + 1) * TILE_SIZE;
            else return;
        }
        else{
            x = -x;
            if(x % TILE_SIZE <= TILE_SIZE / 3) x = (x / TILE_SIZE) * TILE_SIZE;
            else if(x % TILE_SIZE >= 2 * TILE_SIZE / 3) x = (x / TILE_SIZE + 1) * TILE_SIZE;
            else return;
            x = -x;
        }
    }
    if(flag == 0){
        curPiece = new BlackPiece(p[0], p[1]);
        flag = 1;
    }
    else{
        curPiece = new WhitePiece(p[0], p[1]);
        flag = 0;
    }
    scene->addItem(curPiece);
    judge(p[0], p[1], curPiece->data(PIECE_TYPE));
}

void GameController::judge(int x, int y, QVariant type)
{
    int i = x, count = 0;
    QGraphicsItem *tmp;

    // x axis
    while(i >= -300){
        tmp = scene->itemAt(QPointF(i, y), QTransform());
        if(!tmp) break;
        if(tmp->data(PIECE_TYPE) == type){
            count++;
            i -= TILE_SIZE;
        }
        else break;
    }
    i = x + TILE_SIZE;
    while(i <= 300){
        tmp = scene->itemAt(QPointF(i, y), QTransform());
        if(!tmp) break;
        if(tmp->data(PIECE_TYPE) == type){
            count++;
            i += TILE_SIZE;
        }
        else break;
    }
    if(count >= 5){
        if(type == 1) emit win("Black");
        else emit win("White");
        return;
    }

    // y axis
    count = 0;
    i = y;
    while(i >= -300){
        tmp = scene->itemAt(QPointF(x, i), QTransform());
        if(!tmp) break;
        if(tmp->data(PIECE_TYPE) == type){
            count++;
            i -= TILE_SIZE;
        }
        else break;
    }
    i = y + TILE_SIZE;
    while(i <= 300){
        tmp = scene->itemAt(QPointF(x, i), QTransform());
        if(!tmp) break;
        if(tmp->data(PIECE_TYPE) == type){
            count++;
            i += TILE_SIZE;
        }
        else break;
    }
    if(count >= 5){
        if(type == 1) emit win("Black");
        else emit win("White");
        return;
    }

    // \ axis
    count = 0;
    i = x;
    int j = y;
    while(i >= -300 && j >= -300){
        tmp = scene->itemAt(QPointF(i, j), QTransform());
        if(!tmp) break;
        if(tmp->data(PIECE_TYPE) == type){
            count++;
            i -= TILE_SIZE;
            j -= TILE_SIZE;
        }
        else break;
    }
    i = x + TILE_SIZE;
    j = y + TILE_SIZE;
    while(i <= 300 && j <= 300){
        tmp = scene->itemAt(QPointF(i, j), QTransform());
        if(!tmp) break;
        if(tmp->data(PIECE_TYPE) == type){
            count++;
            i += TILE_SIZE;
            j += TILE_SIZE;
        }
        else break;
    }
    if(count >= 5){
        if(type == 1) emit win("Black");
        else emit win("White");
        return;
    }

    // / axis
    count = 0;
    i = x;
    j = y;
    while(i >= -300 && j <= 300){
        tmp = scene->itemAt(QPointF(i, j), QTransform());
        if(!tmp) break;
        if(tmp->data(PIECE_TYPE) == type){
            count++;
            i -= TILE_SIZE;
            j += TILE_SIZE;
        }
        else break;
    }
    i = x + TILE_SIZE;
    j = y - TILE_SIZE;
    while(i <= 300 && j >= -300){
        tmp = scene->itemAt(QPointF(i, j), QTransform());
        if(!tmp) break;
        if(tmp->data(PIECE_TYPE) == type){
            count++;
            i += TILE_SIZE;
            j -= TILE_SIZE;
        }
        else break;
    }
    if(count >= 5){
        if(type == 1) emit win("Black");
        else emit win("White");
        return;
    }
}
