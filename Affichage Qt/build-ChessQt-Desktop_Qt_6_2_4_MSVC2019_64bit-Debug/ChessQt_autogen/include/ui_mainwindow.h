/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Titre;
    QLabel *Pieces_prises_titre;
    QLabel *affichage_pieces_prises;
    QTextEdit *textEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_10;
    QLabel *label_9;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1070, 615);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Titre = new QLabel(centralwidget);
        Titre->setObjectName(QString::fromUtf8("Titre"));
        Titre->setGeometry(QRect(280, 10, 271, 51));
        QFont font;
        font.setPointSize(26);
        Titre->setFont(font);
        Pieces_prises_titre = new QLabel(centralwidget);
        Pieces_prises_titre->setObjectName(QString::fromUtf8("Pieces_prises_titre"));
        Pieces_prises_titre->setGeometry(QRect(10, 80, 141, 51));
        QFont font1;
        font1.setPointSize(13);
        Pieces_prises_titre->setFont(font1);
        affichage_pieces_prises = new QLabel(centralwidget);
        affichage_pieces_prises->setObjectName(QString::fromUtf8("affichage_pieces_prises"));
        affichage_pieces_prises->setGeometry(QRect(10, 220, 151, 61));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 300, 111, 31));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(280, 81, 771, 51));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_11);

        label_15 = new QLabel(widget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_15);

        label_16 = new QLabel(widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_16);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_14);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_13);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_12);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_10);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_9);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(280, 140, 771, 421));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(150, 140, 101, 421));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_7);

        label_4 = new QLabel(widget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        label_8 = new QLabel(widget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_8);

        label_5 = new QLabel(widget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(widget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_6);

        label_3 = new QLabel(widget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        label_2 = new QLabel(widget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        label = new QLabel(widget2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1070, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Titre->setText(QCoreApplication::translate("MainWindow", "Projet Echecs", nullptr));
        Pieces_prises_titre->setText(QCoreApplication::translate("MainWindow", "Pi\303\250ces prises : ", nullptr));
        affichage_pieces_prises->setText(QCoreApplication::translate("MainWindow", "Input d\303\251placement", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
