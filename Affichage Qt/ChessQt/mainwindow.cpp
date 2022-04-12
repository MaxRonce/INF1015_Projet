
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "classes.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Echiquier echiquier = Echiquier();
    int k = 1;
    for (int i = 0; i < 8; ++i) {

            for (int j = 0; j < 8; ++j) {
                QLabel* labelTemp = new QLabel(QString(echiquier.board[i][j]));
                labelTemp->setAlignment(Qt::AlignCenter);
                //labelTemp->setStyleSheet("QLabel { background-color : #FFFFFF; color : black; border: 1px solid black;}");
                if(k%2 == 0){
                    labelTemp->setStyleSheet("QLabel { background-color : #616161; color : black; border: 1px solid black; }"
                                             "QLabel::item::hover {background-color : #FFFFFF}");

                }

                else{
                    labelTemp->setStyleSheet("QLabel { background-color : #FFFFFF; color : black; border: 1px solid black;}"
                                             "QLabel::item::hover {background-color : #616161}");
                }
                ui->gridLayout->addWidget(labelTemp, i, j);
                k = k+1;
            }
            k= k +1;
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

