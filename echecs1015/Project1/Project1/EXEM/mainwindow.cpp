#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Game.h"
#include <QWidget>
#include <iostream>
#include <QLabel>



const QString names[64] =
   {
         "h8","g8","f8","e8","d8","c8","b8","a8",
         "h7","g7","f7","e7","d7","c7","b7","a7",
         "h6","g6","f6","e6","d6","c6","b6","a6",
         "h5","g5","f5","e5","d5","c5","b5","a5",
         "h4","g4","f4","e4","d4","c4","b4","a4",
         "h3","g3","f3","e3","d3","c3","b3","a3",
         "h2","g2","f2","e2","d2","c2","b2","a2",
         "h1","g1","f1","e1","d1","c1","b1","a1"
   };

namespace images{

    std::vector<const char*> imagesWhite{":/echec/Images/WhiteRook.png",":/echec/Images/WhiteKnight.png",
                                      ":/echec/Images/WhiteBishop.png",":/echec/Images/WhiteQueen.png",
                                      ":/echec/Images/WhiteKing.png",":/echec/Images/WhiteBishop.png",
                                      ":/echec/Images/WhiteKnight.png",":/echec/Images/WhiteRook.png"};
    std::vector<const char*> imagesBlack{":/echec/Images/BlackRook.png",":/echec/Images/BlackKnight.png",
                                      ":/echec/Images/BlackBishop.png",":/echec/Images/BlackQueen.png",
                                      ":/echec/Images/BlackKing.png",":/echec/Images/BlackBishop.png",
                                      ":/echec/Images/BlackKnight.png",":/echec/Images/BlackRook.png"};

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
   createButtons();
   connect(this, SIGNAL(sendSignal(QString)), &game_, SLOT(getInput(QString)));
   connect(&game_, SIGNAL(sendResponse(QString)), this, SLOT(getResponse(QString)));
  // ui->label->setStyleSheet("QLabel{font-size: 18pt;}");
   ui->label->setStyleSheet("QLabel { font-size: 18pt; background-color : darkCyan; color : black;border: 3px solid black; }");
   ui->label->setAlignment(Qt::AlignCenter);
   ui->label_2->setStyleSheet("QLabel{font-size: 16pt; background-color : white; color : black;border: 3px solid black;}");
   ui->label_2->setAlignment(Qt::AlignCenter);
   connect(&game_, SIGNAL(colorChange()), this, SLOT(guiColor()));
}


void MainWindow::guiColor(){
    if(colorCount%2==0){
        ui->label_2->setText("White's Turn");
    }
    else
    {
         ui->label_2->setText("Black's Turn");
    }
    ++colorCount;
}
void MainWindow::defaultGameWind(){
    initialize();
    game_.defaultMode();

}
//void MainWindow::restartGameWind(){
 //  colorCount=1;
 //   move="";
 //   ui->label->setText("Welcome to ChessMaster");
 //   ui->label_2->setText("");
 //   game_.restart();
 //   for(int i = 0; i<8;++i){
  //      for(int j =0; j<8;++j){
  //      qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i,j)->widget())->setIcon(QIcon());
 //       }
  // }

//}
void MainWindow::createButtons(){
    int k = 1;
    const QSize btnSize = QSize(100, 100);
    auto defaultGame = ui->pushButton;
    defaultGame->setText("Default Game");
    defaultGame->setFont(QFont("", 10));
    connect(defaultGame, SIGNAL(clicked()), this, SLOT(defaultGameWind()));
    //auto restart = ui->pushButton_2;
    //restart->setText("Restart Game");
    //restart->setFont(QFont("", 10));
    //connect(restart, SIGNAL(clicked()), this, SLOT(restartGameWind()));
       for (int i = 0; i < 8; ++i) {

               for (int j = 0; j < 8; ++j) {
                   QPushButton* button = new QPushButton();
                   if(k%2 == 0)
                   {
                       button->setStyleSheet("background-color: darkCyan");
                       button->setFixedSize(btnSize);

                   }
                   else
                   {
                      button->setStyleSheet("background-color: yellow");
                      button->setFixedSize(btnSize);


                   }
                   ui->gridLayout->addWidget(button, i, j);
                   ui->gridLayout->setSpacing(0);
                   k = k+1;
               }
               k= k +1;
        }

}
void MainWindow::setButtonName(){
     int k =0;
     for(int i =0;i<8;++i){
        for(int j = 0; j<8; ++j){
            auto button = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i,j)->widget());
            button->setObjectName(names[k]);
            connect(button, SIGNAL(clicked()), this, SLOT(setIcon()));
            ++k;
        }
     }

}
void MainWindow::setIcon(){
    QPushButton* target = qobject_cast<QPushButton*>(sender());
        if (target != nullptr)
        {
                emit sendSignal(target->objectName());
        }
}

void MainWindow::initialize(){
    using namespace images;
    setButtonName();
    for(int i = 0; i<8;++i){
        qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0,i)->widget())->setIcon(QIcon(imagesBlack[i]));
        qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0,i)->widget())->setIconSize(QSize(80, 80));
   }

    for(int i = 0; i<8;++i){
        qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(7,i)->widget())->setIcon(QIcon(imagesWhite[i]));
        qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(7,i)->widget())->setIconSize(QSize(80, 80));
   }

   for (int j = 0; j < 8; ++j) {
           qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(1,j)->widget())->setIcon(QIcon(":/echec/Images/BlackPawn.png"));
           qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(1,j)->widget())->setIconSize(QSize(80, 80));
    }

   for (int j = 0; j < 8; ++j) {
           qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(6,j)->widget())->setIcon(QIcon(":/echec/Images/WhitePawn.png"));
           qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(6,j)->widget())->setIconSize(QSize(80, 80));
    }

}





void MainWindow::getResponse(QString response)
{
    try{
    ui->label->setStyleSheet("QLabel { font-size: 18pt; background-color : darkCyan; color : black;border: 3px solid black; }");
    ui->label->setText("");
    using namespace images;
    std::string responseString = response.toStdString();

    if (std::string("Check") == responseString)
    {
        qDebug() << "Check";
        ui->label->setText("Check!");
    }
   else
    {
         ui->label->setText("");
    }

    // If response was "Invalid Move", ignore it
    if (std::string( "Check, Invalid Move") == responseString)
    {
        qDebug() <<  "This leaves you in Check, Invalid Move";
        ui->label->setStyleSheet("QLabel { font-size: 15pt;background-color : darkCyan; color : black;border: 3px solid black; }");
        ui->label->setText("this leaves you Check,Invalid Move!");
       return;
    }
    if (std::string("Invalid Move") == responseString)
    {
        qDebug() << "Invalid Move";
        ui->label->setText("Invalid Move!");
       return;
    }
   else if (std::string("Checkmate") == responseString)
    {
        qDebug() << "Checkmate!";
        ui->label->setText("Checkmate!");
        return;
    }
    else if (std::string("Stalemate") == responseString)
    {
        qDebug() << "Stalemate!";
        ui->label->setText("Stalemate!");
        return;
    }
    // Otherwise, use the response from Game to move the correct pieces
    else
    {
        qDebug() << "Display got permission from Game to move icons.";
        qDebug() << "The response Game sent back was " << response;
        if (response == "Castle White Kingside")
        {
            qDebug() << "Display needs to castle white kingside.";
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(7,4)->widget())->setIcon(QIcon());//king to remove
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(7,7)->widget())->setIcon(QIcon());//rook to remove
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(7,6)->widget())->setIcon(QIcon(imagesWhite[4]));; // new king
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(7,5)->widget())->setIcon(QIcon(imagesWhite[0])); //new rook
        } else if (response == "Castle White Queenside")
        {
            qDebug() << "Display needs to castle white queenside.";
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(7,4)->widget())->setIcon(QIcon());//king to remove
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(7,0)->widget())->setIcon(QIcon());//rook to remove
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(7,2)->widget())->setIcon(QIcon(imagesWhite[4]));; // new king
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(7,3)->widget())->setIcon(QIcon(imagesWhite[0])); //new rook
        } else if (response == "Castle Black Kingside")
        {
            qDebug() << "Display needs to castle black kingside.";
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0,4)->widget())->setIcon(QIcon());//king to remove
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0,7)->widget())->setIcon(QIcon());//rook to remove
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0,6)->widget())->setIcon(QIcon(imagesBlack[4]));; // new king
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0,5)->widget())->setIcon(QIcon(imagesBlack[0])); //new rook
        } else if (response == "Castle Black Queenside")
        {
            qDebug() << "Display needs to castle black queenside.";
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0,4)->widget())->setIcon(QIcon());//king to remove
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0,0)->widget())->setIcon(QIcon());//rook to remove
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0,2)->widget())->setIcon(QIcon(imagesBlack[4]));; // new king
            qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0,3)->widget())->setIcon(QIcon(imagesBlack[0])); //new rook
        }
        else
        {
            QString firstSpace = "";
            QString secondSpace = "";
            firstSpace += response[0];
            firstSpace += response[1];
            secondSpace += response[2];
            secondSpace += response[3];

            QIcon temp;
            for (int i=0; i<8; i++ )
            {
                for (int j=0; j<8; j++ )
                {
                    auto button = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i,j)->widget());
                    if (button->objectName() == firstSpace)
                    {
                        temp = button->icon();
                        button->setIcon(QIcon());//clear image
                    }
                }
            }
            for (int i=0; i<8; i++ )
            {
                for (int j=0; j<8; j++ )
                {
                    auto button = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i,j)->widget());
                    if (button->objectName() == secondSpace)
                    {
                        button->setIcon(temp);
                        button->setIconSize(QSize(80, 80));
                    }
                }
            }
        }
    }
    }
    catch (InstancesKingException& except) {
                    std::cout << "Execution Error : " << except.what() << std::endl;
                }
}






