/********************************************************************************
** Form generated from reading UI file 'controlpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANEL_H
#define UI_CONTROLPANEL_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPanel
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *generalTab;
    QGridLayout *gridLayout_3;
    QTreeWidget *sensorsTreeWidget;
    QLabel *attachedDevicesLabel;
    QTreeWidget *streamsTreeWidget;
    QGroupBox *openniGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *openniBuildNumberLabel;
    QLabel *openniMaintenanceBuildNumberLabel;
    QLabel *openniMajorVersionNumber;
    QLabel *openniMinorVersionNumber;
    QLabel *streamsLabel;
    QPushButton *enumerateDevicesButton;
    QLabel *aboutLabel;
    QWidget *filtrationTab;
    QWidget *outputTab;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *outputTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ControlPanel)
    {
        if (ControlPanel->objectName().isEmpty())
            ControlPanel->setObjectName(QStringLiteral("ControlPanel"));
        ControlPanel->setEnabled(true);
        ControlPanel->resize(470, 378);
        ControlPanel->setMaximumSize(QSize(470, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral("ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        ControlPanel->setWindowIcon(icon);
        ControlPanel->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        centralwidget = new QWidget(ControlPanel);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        generalTab = new QWidget();
        generalTab->setObjectName(QStringLiteral("generalTab"));
        gridLayout_3 = new QGridLayout(generalTab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        sensorsTreeWidget = new QTreeWidget(generalTab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        sensorsTreeWidget->setHeaderItem(__qtreewidgetitem);
        sensorsTreeWidget->setObjectName(QStringLiteral("sensorsTreeWidget"));
        sensorsTreeWidget->setMaximumSize(QSize(200, 16777215));

        gridLayout_3->addWidget(sensorsTreeWidget, 2, 0, 1, 1);

        attachedDevicesLabel = new QLabel(generalTab);
        attachedDevicesLabel->setObjectName(QStringLiteral("attachedDevicesLabel"));
        attachedDevicesLabel->setMinimumSize(QSize(0, 16));
        attachedDevicesLabel->setMaximumSize(QSize(16777215, 16));

        gridLayout_3->addWidget(attachedDevicesLabel, 1, 0, 1, 1);

        streamsTreeWidget = new QTreeWidget(generalTab);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        streamsTreeWidget->setHeaderItem(__qtreewidgetitem1);
        streamsTreeWidget->setObjectName(QStringLiteral("streamsTreeWidget"));
        streamsTreeWidget->setEnabled(false);
        streamsTreeWidget->setMaximumSize(QSize(250, 16777215));

        gridLayout_3->addWidget(streamsTreeWidget, 2, 1, 1, 1);

        openniGroupBox = new QGroupBox(generalTab);
        openniGroupBox->setObjectName(QStringLiteral("openniGroupBox"));
        openniGroupBox->setMinimumSize(QSize(0, 69));
        gridLayout_2 = new QGridLayout(openniGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        openniBuildNumberLabel = new QLabel(openniGroupBox);
        openniBuildNumberLabel->setObjectName(QStringLiteral("openniBuildNumberLabel"));
        openniBuildNumberLabel->setEnabled(false);

        gridLayout_2->addWidget(openniBuildNumberLabel, 0, 0, 1, 1);

        openniMaintenanceBuildNumberLabel = new QLabel(openniGroupBox);
        openniMaintenanceBuildNumberLabel->setObjectName(QStringLiteral("openniMaintenanceBuildNumberLabel"));
        openniMaintenanceBuildNumberLabel->setEnabled(false);

        gridLayout_2->addWidget(openniMaintenanceBuildNumberLabel, 1, 0, 1, 1);

        openniMajorVersionNumber = new QLabel(openniGroupBox);
        openniMajorVersionNumber->setObjectName(QStringLiteral("openniMajorVersionNumber"));
        openniMajorVersionNumber->setEnabled(false);

        gridLayout_2->addWidget(openniMajorVersionNumber, 0, 1, 1, 1);

        openniMinorVersionNumber = new QLabel(openniGroupBox);
        openniMinorVersionNumber->setObjectName(QStringLiteral("openniMinorVersionNumber"));
        openniMinorVersionNumber->setEnabled(false);

        gridLayout_2->addWidget(openniMinorVersionNumber, 1, 1, 1, 1);


        gridLayout_3->addWidget(openniGroupBox, 0, 0, 1, 2);

        streamsLabel = new QLabel(generalTab);
        streamsLabel->setObjectName(QStringLiteral("streamsLabel"));
        streamsLabel->setEnabled(false);

        gridLayout_3->addWidget(streamsLabel, 1, 1, 1, 1);

        enumerateDevicesButton = new QPushButton(generalTab);
        enumerateDevicesButton->setObjectName(QStringLiteral("enumerateDevicesButton"));

        gridLayout_3->addWidget(enumerateDevicesButton, 3, 0, 1, 1);

        aboutLabel = new QLabel(generalTab);
        aboutLabel->setObjectName(QStringLiteral("aboutLabel"));
        aboutLabel->setEnabled(false);
        aboutLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(aboutLabel, 3, 1, 1, 1);

        tabWidget->addTab(generalTab, QString());
        filtrationTab = new QWidget();
        filtrationTab->setObjectName(QStringLiteral("filtrationTab"));
        tabWidget->addTab(filtrationTab, QString());
        outputTab = new QWidget();
        outputTab->setObjectName(QStringLiteral("outputTab"));
        gridLayout_4 = new QGridLayout(outputTab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        outputTextEdit = new QPlainTextEdit(outputTab);
        outputTextEdit->setObjectName(QStringLiteral("outputTextEdit"));
        outputTextEdit->setEnabled(true);
        outputTextEdit->setReadOnly(true);
        outputTextEdit->setBackgroundVisible(false);

        gridLayout_4->addWidget(outputTextEdit, 0, 0, 1, 1);

        tabWidget->addTab(outputTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 2);

        ControlPanel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ControlPanel);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 470, 21));
        ControlPanel->setMenuBar(menubar);
        statusbar = new QStatusBar(ControlPanel);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ControlPanel->setStatusBar(statusbar);
        QWidget::setTabOrder(tabWidget, outputTextEdit);
        QWidget::setTabOrder(outputTextEdit, streamsTreeWidget);
        QWidget::setTabOrder(streamsTreeWidget, enumerateDevicesButton);
        QWidget::setTabOrder(enumerateDevicesButton, sensorsTreeWidget);

        retranslateUi(ControlPanel);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ControlPanel);
    } // setupUi

    void retranslateUi(QMainWindow *ControlPanel)
    {
        ControlPanel->setWindowTitle(QApplication::translate("ControlPanel", "SmartSensor Control Panel", 0));
        attachedDevicesLabel->setText(QApplication::translate("ControlPanel", "Attached devices", 0));
        openniGroupBox->setTitle(QApplication::translate("ControlPanel", "OpenNI Info", 0));
        openniBuildNumberLabel->setText(QApplication::translate("ControlPanel", "<html><head/><body><p>Build number:</p></body></html>", 0));
        openniMaintenanceBuildNumberLabel->setText(QApplication::translate("ControlPanel", "Maintenance build number:", 0));
        openniMajorVersionNumber->setText(QApplication::translate("ControlPanel", "Major version number:", 0));
        openniMinorVersionNumber->setText(QApplication::translate("ControlPanel", "Minor version number:", 0));
        streamsLabel->setText(QApplication::translate("ControlPanel", "Streams", 0));
        enumerateDevicesButton->setText(QApplication::translate("ControlPanel", "Refresh", 0));
        aboutLabel->setText(QApplication::translate("ControlPanel", "SmartSensor 2012-2014\302\251", 0));
        tabWidget->setTabText(tabWidget->indexOf(generalTab), QApplication::translate("ControlPanel", "General", 0));
        tabWidget->setTabText(tabWidget->indexOf(filtrationTab), QApplication::translate("ControlPanel", "Filtration", 0));
        outputTextEdit->setDocumentTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(outputTab), QApplication::translate("ControlPanel", "Output", 0));
    } // retranslateUi

};

namespace Ui {
    class ControlPanel: public Ui_ControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANEL_H
