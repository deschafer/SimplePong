/********************************************************************************
** Form generated from reading UI file 'SimplePong.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEPONG_H
#define UI_SIMPLEPONG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimplePongClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SimplePongClass)
    {
        if (SimplePongClass->objectName().isEmpty())
            SimplePongClass->setObjectName(QString::fromUtf8("SimplePongClass"));
        SimplePongClass->resize(600, 400);
        menuBar = new QMenuBar(SimplePongClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        SimplePongClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SimplePongClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SimplePongClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SimplePongClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SimplePongClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SimplePongClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SimplePongClass->setStatusBar(statusBar);

        retranslateUi(SimplePongClass);

        QMetaObject::connectSlotsByName(SimplePongClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimplePongClass)
    {
        SimplePongClass->setWindowTitle(QCoreApplication::translate("SimplePongClass", "SimplePong", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimplePongClass: public Ui_SimplePongClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEPONG_H
