/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListView *RecordedFiles;
    QListView *FilteredFiles;
    QPushButton *SearchStart;
    QCheckBox *FuzzySearchMode;
    QComboBox *SearchContent;
    QPlainTextEdit *SearchTarget;
    QPushButton *BrowseBT;
    QPushButton *ClearLBT;
    QPushButton *OpenFileBT;
    QPushButton *AddBT;
    QPushButton *DeleteSelectedItem;
    QPushButton *ClearRBT;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 720));
        MainWindow->setAcceptDrops(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        RecordedFiles = new QListView(centralwidget);
        RecordedFiles->setObjectName("RecordedFiles");
        RecordedFiles->setGeometry(QRect(50, 140, 571, 541));
        FilteredFiles = new QListView(centralwidget);
        FilteredFiles->setObjectName("FilteredFiles");
        FilteredFiles->setGeometry(QRect(660, 140, 571, 541));
        QFont font;
        font.setPointSize(9);
        FilteredFiles->setFont(font);
        SearchStart = new QPushButton(centralwidget);
        SearchStart->setObjectName("SearchStart");
        SearchStart->setGeometry(QRect(1180, 20, 51, 51));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        SearchStart->setIcon(icon);
        SearchStart->setIconSize(QSize(32, 32));
        FuzzySearchMode = new QCheckBox(centralwidget);
        FuzzySearchMode->setObjectName("FuzzySearchMode");
        FuzzySearchMode->setGeometry(QRect(1070, 50, 101, 21));
        FuzzySearchMode->setChecked(false);
        FuzzySearchMode->setProperty("FuzzyMode", QVariant(false));
        SearchContent = new QComboBox(centralwidget);
        SearchContent->setObjectName("SearchContent");
        SearchContent->setGeometry(QRect(1070, 20, 101, 31));
        SearchContent->setEditable(false);
        SearchTarget = new QPlainTextEdit(centralwidget);
        SearchTarget->setObjectName("SearchTarget");
        SearchTarget->setGeometry(QRect(50, 20, 1011, 51));
        QFont font1;
        font1.setPointSize(22);
        SearchTarget->setFont(font1);
        BrowseBT = new QPushButton(centralwidget);
        BrowseBT->setObjectName("BrowseBT");
        BrowseBT->setGeometry(QRect(50, 80, 51, 51));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::FolderNew));
        BrowseBT->setIcon(icon1);
        BrowseBT->setIconSize(QSize(24, 24));
        ClearLBT = new QPushButton(centralwidget);
        ClearLBT->setObjectName("ClearLBT");
        ClearLBT->setGeometry(QRect(170, 80, 51, 51));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        ClearLBT->setIcon(icon2);
        ClearLBT->setIconSize(QSize(24, 24));
        OpenFileBT = new QPushButton(centralwidget);
        OpenFileBT->setObjectName("OpenFileBT");
        OpenFileBT->setGeometry(QRect(1170, 80, 51, 51));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::FolderOpen));
        OpenFileBT->setIcon(icon3);
        OpenFileBT->setIconSize(QSize(24, 24));
        AddBT = new QPushButton(centralwidget);
        AddBT->setObjectName("AddBT");
        AddBT->setGeometry(QRect(110, 80, 51, 51));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        AddBT->setIcon(icon4);
        AddBT->setIconSize(QSize(24, 24));
        DeleteSelectedItem = new QPushButton(centralwidget);
        DeleteSelectedItem->setObjectName("DeleteSelectedItem");
        DeleteSelectedItem->setGeometry(QRect(230, 80, 51, 51));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        DeleteSelectedItem->setIcon(icon5);
        DeleteSelectedItem->setIconSize(QSize(24, 24));
        ClearRBT = new QPushButton(centralwidget);
        ClearRBT->setObjectName("ClearRBT");
        ClearRBT->setGeometry(QRect(1110, 80, 51, 51));
        ClearRBT->setIcon(icon2);
        ClearRBT->setIconSize(QSize(24, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SearchStart->setText(QString());
        FuzzySearchMode->setText(QCoreApplication::translate("MainWindow", "\346\250\241\347\263\212\346\220\234\347\264\242", nullptr));
        SearchContent->setCurrentText(QString());
        BrowseBT->setText(QString());
        ClearLBT->setText(QString());
        OpenFileBT->setText(QString());
        AddBT->setText(QString());
        DeleteSelectedItem->setText(QString());
        ClearRBT->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
