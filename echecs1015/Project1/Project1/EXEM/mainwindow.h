#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Game.h"
#include "InstancesKingException.h"
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
    void defaultGameWind();
    void restartGameWind();
    void guiColor();
signals:
   void sendSignal(QString);
private:
   int colorCount=1;
    Ui::MainWindow *ui;
    Game game_;
    QString move;

};
#endif // MAINWINDOW_H
