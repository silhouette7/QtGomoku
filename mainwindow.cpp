#include <QToolBar>
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "gamecontroller.h"
#include "constants.h"
#include "board.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      game(new GameController(scene, this))
{
    setCentralWidget(view);
    resize(800, 800);


    initScene();

    startAction = new QAction(QIcon(":/images/doc-start"), tr("&Start"), this);
    QToolBar *toolBar = addToolBar(tr("&Tool Bar"));
    toolBar->addAction(startAction);
    connect(startAction, &QAction::triggered, this, &MainWindow::start);
    connect(game, &GameController::win, this, &MainWindow::end);
}

void MainWindow::start(){
    QMessageBox msgBox(this);
    msgBox.setText(tr("Start a new game?"));
    msgBox.setStandardButtons(QMessageBox::Yes
                              | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int result = msgBox.exec();
    switch(result){
    case QMessageBox::Yes:
        game->start();
        break;
    case QMessageBox::No:
        break;
    }
}

void MainWindow::initScene(){
    scene->setSceneRect(-300, -300, 600, 600);
    view->setSceneRect(-300, -300, 600, 600);
}

void MainWindow::end(const QString &name){
    QMessageBox msgBox(this);
    msgBox.setText(name + " player win!");
    msgBox.setInformativeText(tr("Start a new game?"));
    msgBox.setStandardButtons(QMessageBox::Yes
                              | QMessageBox::No);
    int result = msgBox.exec();
    switch(result){
    case QMessageBox::Yes:
        game->start();
        break;
    case QMessageBox::No:
        game->gameOver();
        break;
    }
}

MainWindow::~MainWindow()
{
}
