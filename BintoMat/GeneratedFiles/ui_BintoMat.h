/********************************************************************************
** Form generated from reading UI file 'BintoMat.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINTOMAT_H
#define UI_BINTOMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BintoMatClass
{
public:
    QAction *openAction;
    QAction *colorAction;
    QAction *saveAction;
    QWidget *centralWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BintoMatClass)
    {
        if (BintoMatClass->objectName().isEmpty())
            BintoMatClass->setObjectName(QStringLiteral("BintoMatClass"));
        BintoMatClass->resize(592, 441);
        openAction = new QAction(BintoMatClass);
        openAction->setObjectName(QStringLiteral("openAction"));
        colorAction = new QAction(BintoMatClass);
        colorAction->setObjectName(QStringLiteral("colorAction"));
        saveAction = new QAction(BintoMatClass);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        centralWidget = new QWidget(BintoMatClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(160, 40, 320, 240));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 318, 238));
        scrollArea->setWidget(scrollAreaWidgetContents);
        BintoMatClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BintoMatClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 592, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        BintoMatClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BintoMatClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BintoMatClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BintoMatClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BintoMatClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(openAction);
        menuFile->addAction(colorAction);
        menuFile->addAction(saveAction);

        retranslateUi(BintoMatClass);

        QMetaObject::connectSlotsByName(BintoMatClass);
    } // setupUi

    void retranslateUi(QMainWindow *BintoMatClass)
    {
        BintoMatClass->setWindowTitle(QApplication::translate("BintoMatClass", "BintoMat", 0));
        openAction->setText(QApplication::translate("BintoMatClass", "open", 0));
        colorAction->setText(QApplication::translate("BintoMatClass", "color", 0));
        saveAction->setText(QApplication::translate("BintoMatClass", "save", 0));
        menuFile->setTitle(QApplication::translate("BintoMatClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class BintoMatClass: public Ui_BintoMatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINTOMAT_H
