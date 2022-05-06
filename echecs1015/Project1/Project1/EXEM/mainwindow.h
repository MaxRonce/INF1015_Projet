#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Game.h"
#pragma warning(push, 0)
#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsItem>
#pragma pop()

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget *parent = nullptr);
    ~MainWindow() override = default;
    void createButtons();
     void initialize();
     void setButtonName();
public slots:
    void setIcon();
    void getResponse(QString response);
signals:
   void sendSignal(QString);
private:
    Ui::MainWindow *ui;
    Game game_;
    QString move;
     Piece::Color turnColor;
     QGraphicsTextItem* turn;
     //QGraphicsTextItem* check;

};
#endif // MAINWINDOW_H
