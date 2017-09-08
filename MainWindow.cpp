#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->menuWidget);
/*
    scene = new QGraphicsScene(ui->menuWidget);
    view = new QGraphicsView(scene);
      //  setCentralWidget(view);
    QImage image(":/card/Gwent Cards/001_VranWarrior.png");
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    view->show();
*/


    connect(ui->deckButton, SIGNAL(clicked(bool)), this, SLOT(goToDeck()));

    account = new Account(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goToDeck()
{
    deckControl = new DeckControl(this, account, this);
    deckControl->run();

    ui->setupUi(this);
    connect(ui->deckButton, SIGNAL(clicked(bool)), this, SLOT(goToDeck()));
    this->setCentralWidget(ui->menuWidget);
}