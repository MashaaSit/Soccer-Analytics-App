/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include </home/masha/projectQt/include/GameFieldLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *mainLayout;
    GameFieldLabel *gamefieldLabel;
    QWidget *rightPanel;
    QVBoxLayout *rightLayout;
    QHBoxLayout *teamInfoLayout;
    QSpacerItem *horizontalSpacerLeft;
    QLabel *firstTeamLabel;
    QLabel *label;
    QLabel *secondTeamLabel;
    QSpacerItem *horizontalSpacerRight;
    QHBoxLayout *buttonsAttackLayout;
    QPushButton *prevAttackButton;
    QPushButton *drawAttackButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #F8F7F7;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainLayout = new QHBoxLayout(centralwidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        gamefieldLabel = new GameFieldLabel(centralwidget);
        gamefieldLabel->setObjectName(QString::fromUtf8("gamefieldLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gamefieldLabel->sizePolicy().hasHeightForWidth());
        gamefieldLabel->setSizePolicy(sizePolicy);

        mainLayout->addWidget(gamefieldLabel);

        rightPanel = new QWidget(centralwidget);
        rightPanel->setObjectName(QString::fromUtf8("rightPanel"));
        rightPanel->setMaximumWidth(500);
        rightLayout = new QVBoxLayout(rightPanel);
        rightLayout->setObjectName(QString::fromUtf8("rightLayout"));
        rightLayout->setContentsMargins(0, 0, 0, 0);
        teamInfoLayout = new QHBoxLayout();
        teamInfoLayout->setObjectName(QString::fromUtf8("teamInfoLayout"));
        horizontalSpacerLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        teamInfoLayout->addItem(horizontalSpacerLeft);

        firstTeamLabel = new QLabel(rightPanel);
        firstTeamLabel->setObjectName(QString::fromUtf8("firstTeamLabel"));
        firstTeamLabel->setStyleSheet(QString::fromUtf8("\n"
"                                                    background-color: #FFA680;\n"
"                                                    border-radius: 4px;\n"
"                                                    padding: 2px 4px;\n"
"                                                "));

        teamInfoLayout->addWidget(firstTeamLabel);

        label = new QLabel(rightPanel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("\n"
"                                                    color:white;\n"
"                                                    background-color: #333333;\n"
"                                                    border-radius: 4px;\n"
"                                                    padding: 2px 4px;\n"
"                                                "));

        teamInfoLayout->addWidget(label);

        secondTeamLabel = new QLabel(rightPanel);
        secondTeamLabel->setObjectName(QString::fromUtf8("secondTeamLabel"));
        secondTeamLabel->setStyleSheet(QString::fromUtf8("\n"
"                                                    background-color: #FFA680;\n"
"                                                    border-radius: 4px;\n"
"                                                    padding: 2px 4px;\n"
"                                                "));

        teamInfoLayout->addWidget(secondTeamLabel);

        horizontalSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        teamInfoLayout->addItem(horizontalSpacerRight);


        rightLayout->addLayout(teamInfoLayout);

        buttonsAttackLayout = new QHBoxLayout();
        buttonsAttackLayout->setObjectName(QString::fromUtf8("buttonsAttackLayout"));
        prevAttackButton = new QPushButton(rightPanel);
        prevAttackButton->setObjectName(QString::fromUtf8("prevAttackButton"));

        buttonsAttackLayout->addWidget(prevAttackButton);

        drawAttackButton = new QPushButton(rightPanel);
        drawAttackButton->setObjectName(QString::fromUtf8("drawAttackButton"));

        buttonsAttackLayout->addWidget(drawAttackButton);


        rightLayout->addLayout(buttonsAttackLayout);

        checkBox = new QCheckBox(rightPanel);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        rightLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(rightPanel);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        rightLayout->addWidget(checkBox_2);

        label_3 = new QLabel(rightPanel);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        rightLayout->addWidget(label_3);

        lineEdit = new QLineEdit(rightPanel);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        rightLayout->addWidget(lineEdit);


        mainLayout->addWidget(rightPanel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
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
        label->setText(QCoreApplication::translate("MainWindow", "\320\220\321\202\320\260\320\272\321\203\321\216\321\211\320\260\321\217 \320\272\320\276\320\274\320\260\320\275\320\264\320\260", nullptr));
        prevAttackButton->setText(QCoreApplication::translate("MainWindow", "hide previous attack", nullptr));
        drawAttackButton->setText(QCoreApplication::translate("MainWindow", "show next attack", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "is_chipped", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "is_foot", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\321\201\320\272\320\276\320\273\321\214\320\272\320\276 \320\277\320\260\321\201\321\201\320\276\320\262 \320\277\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\262 \320\260\321\202\320\260\320\272\320\265?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
