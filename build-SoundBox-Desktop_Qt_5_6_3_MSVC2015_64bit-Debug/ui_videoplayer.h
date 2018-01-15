/********************************************************************************
** Form generated from reading UI file 'videoplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYER_H
#define UI_VIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_VideoPlayer
{
public:
    QAction *actionAdd_Camera;
    QAction *actionAdd_Camera_2;
    QAction *actionPlay;
    QWidget *centralWidget;
    VideoWidget *inputFrame;
    VideoWidget *inputFrame_2;
    VideoWidget *outputFrame;
    VideoWidget *outputFrame_2;
    QSlider *equalizerSlider;
    QSlider *saturationSlider;
    QSlider *hueSlider;
    QSlider *toleranceSilder;
    QLabel *hueTextLabel;
    QLabel *toleranceTextLabel;
    QLabel *saturationTextLabel;
    QLabel *equalizerTextLabel;
    QLabel *hueValue;
    QLabel *toleranceValue;
    QLabel *saturationValue;
    QLabel *equalizerValue;
    QCheckBox *medianCheck;
    QCheckBox *openingCheck;
    QLabel *xLabel;
    QLabel *yLabel;
    QLabel *zLabel;
    QLabel *xValue;
    QLabel *yValue;
    QLabel *zValue;
    QLabel *midiOutTextLabel;
    QComboBox *comboBox;
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;
    QMenuBar *menuBar;
    QMenu *menuSelect;
    QMenu *menuPlay;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VideoPlayer)
    {
        if (VideoPlayer->objectName().isEmpty())
            VideoPlayer->setObjectName(QStringLiteral("VideoPlayer"));
        VideoPlayer->resize(1030, 595);
        actionAdd_Camera = new QAction(VideoPlayer);
        actionAdd_Camera->setObjectName(QStringLiteral("actionAdd_Camera"));
        actionAdd_Camera_2 = new QAction(VideoPlayer);
        actionAdd_Camera_2->setObjectName(QStringLiteral("actionAdd_Camera_2"));
        actionPlay = new QAction(VideoPlayer);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        centralWidget = new QWidget(VideoPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputFrame = new VideoWidget(centralWidget);
        inputFrame->setObjectName(QStringLiteral("inputFrame"));
        inputFrame->setGeometry(QRect(30, 30, 301, 221));
        inputFrame->setFrameShape(QFrame::Box);
        inputFrame->setScaledContents(false);
        inputFrame->setAlignment(Qt::AlignCenter);
        inputFrame_2 = new VideoWidget(centralWidget);
        inputFrame_2->setObjectName(QStringLiteral("inputFrame_2"));
        inputFrame_2->setGeometry(QRect(30, 290, 301, 221));
        inputFrame_2->setFrameShape(QFrame::Box);
        inputFrame_2->setScaledContents(false);
        inputFrame_2->setAlignment(Qt::AlignCenter);
        outputFrame = new VideoWidget(centralWidget);
        outputFrame->setObjectName(QStringLiteral("outputFrame"));
        outputFrame->setGeometry(QRect(370, 30, 301, 221));
        outputFrame->setFrameShape(QFrame::Box);
        outputFrame->setScaledContents(false);
        outputFrame->setAlignment(Qt::AlignCenter);
        outputFrame_2 = new VideoWidget(centralWidget);
        outputFrame_2->setObjectName(QStringLiteral("outputFrame_2"));
        outputFrame_2->setGeometry(QRect(370, 290, 301, 221));
        outputFrame_2->setFrameShape(QFrame::Box);
        outputFrame_2->setScaledContents(false);
        outputFrame_2->setAlignment(Qt::AlignCenter);
        equalizerSlider = new QSlider(centralWidget);
        equalizerSlider->setObjectName(QStringLiteral("equalizerSlider"));
        equalizerSlider->setGeometry(QRect(800, 170, 160, 19));
        equalizerSlider->setMinimum(1);
        equalizerSlider->setMaximum(100);
        equalizerSlider->setOrientation(Qt::Horizontal);
        saturationSlider = new QSlider(centralWidget);
        saturationSlider->setObjectName(QStringLiteral("saturationSlider"));
        saturationSlider->setGeometry(QRect(800, 140, 160, 19));
        saturationSlider->setMaximum(255);
        saturationSlider->setOrientation(Qt::Horizontal);
        hueSlider = new QSlider(centralWidget);
        hueSlider->setObjectName(QStringLiteral("hueSlider"));
        hueSlider->setGeometry(QRect(800, 80, 161, 20));
        hueSlider->setStyleSheet(QStringLiteral(""));
        hueSlider->setMaximum(360);
        hueSlider->setOrientation(Qt::Horizontal);
        toleranceSilder = new QSlider(centralWidget);
        toleranceSilder->setObjectName(QStringLiteral("toleranceSilder"));
        toleranceSilder->setGeometry(QRect(800, 110, 161, 19));
        toleranceSilder->setMaximum(30);
        toleranceSilder->setOrientation(Qt::Horizontal);
        hueTextLabel = new QLabel(centralWidget);
        hueTextLabel->setObjectName(QStringLiteral("hueTextLabel"));
        hueTextLabel->setGeometry(QRect(730, 80, 61, 16));
        toleranceTextLabel = new QLabel(centralWidget);
        toleranceTextLabel->setObjectName(QStringLiteral("toleranceTextLabel"));
        toleranceTextLabel->setGeometry(QRect(730, 110, 61, 16));
        saturationTextLabel = new QLabel(centralWidget);
        saturationTextLabel->setObjectName(QStringLiteral("saturationTextLabel"));
        saturationTextLabel->setGeometry(QRect(730, 140, 61, 16));
        equalizerTextLabel = new QLabel(centralWidget);
        equalizerTextLabel->setObjectName(QStringLiteral("equalizerTextLabel"));
        equalizerTextLabel->setGeometry(QRect(730, 170, 61, 16));
        hueValue = new QLabel(centralWidget);
        hueValue->setObjectName(QStringLiteral("hueValue"));
        hueValue->setGeometry(QRect(970, 80, 31, 16));
        hueValue->setMidLineWidth(0);
        hueValue->setAlignment(Qt::AlignCenter);
        toleranceValue = new QLabel(centralWidget);
        toleranceValue->setObjectName(QStringLiteral("toleranceValue"));
        toleranceValue->setGeometry(QRect(970, 110, 31, 16));
        toleranceValue->setMidLineWidth(0);
        toleranceValue->setAlignment(Qt::AlignCenter);
        saturationValue = new QLabel(centralWidget);
        saturationValue->setObjectName(QStringLiteral("saturationValue"));
        saturationValue->setGeometry(QRect(970, 140, 31, 16));
        saturationValue->setMidLineWidth(0);
        saturationValue->setAlignment(Qt::AlignCenter);
        equalizerValue = new QLabel(centralWidget);
        equalizerValue->setObjectName(QStringLiteral("equalizerValue"));
        equalizerValue->setGeometry(QRect(970, 170, 31, 16));
        equalizerValue->setMidLineWidth(0);
        equalizerValue->setAlignment(Qt::AlignCenter);
        medianCheck = new QCheckBox(centralWidget);
        medianCheck->setObjectName(QStringLiteral("medianCheck"));
        medianCheck->setGeometry(QRect(730, 210, 61, 17));
        openingCheck = new QCheckBox(centralWidget);
        openingCheck->setObjectName(QStringLiteral("openingCheck"));
        openingCheck->setGeometry(QRect(800, 210, 71, 17));
        xLabel = new QLabel(centralWidget);
        xLabel->setObjectName(QStringLiteral("xLabel"));
        xLabel->setGeometry(QRect(730, 260, 16, 16));
        yLabel = new QLabel(centralWidget);
        yLabel->setObjectName(QStringLiteral("yLabel"));
        yLabel->setGeometry(QRect(730, 280, 16, 16));
        zLabel = new QLabel(centralWidget);
        zLabel->setObjectName(QStringLiteral("zLabel"));
        zLabel->setGeometry(QRect(730, 300, 16, 16));
        xValue = new QLabel(centralWidget);
        xValue->setObjectName(QStringLiteral("xValue"));
        xValue->setGeometry(QRect(750, 260, 51, 16));
        yValue = new QLabel(centralWidget);
        yValue->setObjectName(QStringLiteral("yValue"));
        yValue->setGeometry(QRect(750, 280, 51, 16));
        zValue = new QLabel(centralWidget);
        zValue->setObjectName(QStringLiteral("zValue"));
        zValue->setGeometry(QRect(750, 300, 51, 16));
        midiOutTextLabel = new QLabel(centralWidget);
        midiOutTextLabel->setObjectName(QStringLiteral("midiOutTextLabel"));
        midiOutTextLabel->setGeometry(QRect(730, 30, 51, 16));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(800, 30, 191, 22));
        xSlider = new QSlider(centralWidget);
        xSlider->setObjectName(QStringLiteral("xSlider"));
        xSlider->setGeometry(QRect(730, 330, 251, 21));
        xSlider->setMaximum(640);
        xSlider->setValue(320);
        xSlider->setOrientation(Qt::Horizontal);
        ySlider = new QSlider(centralWidget);
        ySlider->setObjectName(QStringLiteral("ySlider"));
        ySlider->setGeometry(QRect(730, 370, 251, 21));
        ySlider->setMaximum(480);
        ySlider->setValue(240);
        ySlider->setOrientation(Qt::Horizontal);
        zSlider = new QSlider(centralWidget);
        zSlider->setObjectName(QStringLiteral("zSlider"));
        zSlider->setGeometry(QRect(730, 410, 251, 21));
        zSlider->setMaximum(640);
        zSlider->setValue(320);
        zSlider->setOrientation(Qt::Horizontal);
        VideoPlayer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VideoPlayer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1030, 21));
        menuSelect = new QMenu(menuBar);
        menuSelect->setObjectName(QStringLiteral("menuSelect"));
        menuPlay = new QMenu(menuBar);
        menuPlay->setObjectName(QStringLiteral("menuPlay"));
        VideoPlayer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VideoPlayer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VideoPlayer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VideoPlayer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VideoPlayer->setStatusBar(statusBar);

        menuBar->addAction(menuSelect->menuAction());
        menuBar->addAction(menuPlay->menuAction());
        menuSelect->addAction(actionAdd_Camera);
        menuSelect->addAction(actionAdd_Camera_2);
        menuPlay->addAction(actionPlay);

        retranslateUi(VideoPlayer);
        QObject::connect(hueSlider, SIGNAL(valueChanged(int)), VideoPlayer, SLOT(updateParameters()));
        QObject::connect(toleranceSilder, SIGNAL(valueChanged(int)), VideoPlayer, SLOT(updateParameters()));
        QObject::connect(saturationSlider, SIGNAL(valueChanged(int)), VideoPlayer, SLOT(updateParameters()));
        QObject::connect(equalizerSlider, SIGNAL(valueChanged(int)), VideoPlayer, SLOT(updateParameters()));
        QObject::connect(medianCheck, SIGNAL(toggled(bool)), VideoPlayer, SLOT(updateParameters()));
        QObject::connect(openingCheck, SIGNAL(toggled(bool)), VideoPlayer, SLOT(updateParameters()));

        QMetaObject::connectSlotsByName(VideoPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *VideoPlayer)
    {
        VideoPlayer->setWindowTitle(QApplication::translate("VideoPlayer", "VideoPlayer", Q_NULLPTR));
        actionAdd_Camera->setText(QApplication::translate("VideoPlayer", "Add Camera 1", Q_NULLPTR));
        actionAdd_Camera_2->setText(QApplication::translate("VideoPlayer", "Add Camera 2", Q_NULLPTR));
        actionPlay->setText(QApplication::translate("VideoPlayer", "Play", Q_NULLPTR));
        inputFrame->setText(QString());
        inputFrame_2->setText(QString());
        outputFrame->setText(QString());
        outputFrame_2->setText(QString());
        hueTextLabel->setText(QApplication::translate("VideoPlayer", "Hue", Q_NULLPTR));
        toleranceTextLabel->setText(QApplication::translate("VideoPlayer", "Tolerance", Q_NULLPTR));
        saturationTextLabel->setText(QApplication::translate("VideoPlayer", "Saturation", Q_NULLPTR));
        equalizerTextLabel->setText(QApplication::translate("VideoPlayer", "Equalizer", Q_NULLPTR));
        hueValue->setText(QApplication::translate("VideoPlayer", "0", Q_NULLPTR));
        toleranceValue->setText(QApplication::translate("VideoPlayer", "0", Q_NULLPTR));
        saturationValue->setText(QApplication::translate("VideoPlayer", "0", Q_NULLPTR));
        equalizerValue->setText(QApplication::translate("VideoPlayer", "0", Q_NULLPTR));
        medianCheck->setText(QApplication::translate("VideoPlayer", "Median", Q_NULLPTR));
        openingCheck->setText(QApplication::translate("VideoPlayer", "Opening", Q_NULLPTR));
        xLabel->setText(QApplication::translate("VideoPlayer", "X:", Q_NULLPTR));
        yLabel->setText(QApplication::translate("VideoPlayer", "Y:", Q_NULLPTR));
        zLabel->setText(QApplication::translate("VideoPlayer", "Z:", Q_NULLPTR));
        xValue->setText(QApplication::translate("VideoPlayer", "0", Q_NULLPTR));
        yValue->setText(QApplication::translate("VideoPlayer", "0", Q_NULLPTR));
        zValue->setText(QApplication::translate("VideoPlayer", "0", Q_NULLPTR));
        midiOutTextLabel->setText(QApplication::translate("VideoPlayer", "MIDI out", Q_NULLPTR));
        menuSelect->setTitle(QApplication::translate("VideoPlayer", "Select", Q_NULLPTR));
        menuPlay->setTitle(QApplication::translate("VideoPlayer", "Play", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VideoPlayer: public Ui_VideoPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYER_H
