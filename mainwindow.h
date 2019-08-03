#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QGraphicsView>
#include <QGraphicsScene>

class GameController;
class Board;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void confirm();
    void start();
    void initScene();
    void end(const QString &name);
private:
    QAction *startAction;
    QGraphicsScene *scene;
    QGraphicsView *view;
    GameController *game;
};

#endif // MAINWINDOW_H
