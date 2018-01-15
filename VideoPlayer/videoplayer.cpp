#include <QFileDialog>
#include "videoplayer.h"
#include "ui_videoplayer.h"
#include "brightnessprocessor.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoPlayer)
    , videoThread(new VideoEngine)
    , videoProcessor(new ColorProcessor)
{
    ui->setupUi(this);
    videoThread->setProcessor(videoProcessor);
    connect(videoThread, &VideoEngine::sendInputImage,
            ui->inputFrame, &VideoWidget::setImage);
    connect(videoThread, &VideoEngine::sendProcessedImage,
            ui->processedFrame, &VideoWidget::setImage);
}

VideoPlayer::~VideoPlayer()
{
    delete videoThread;
    delete ui;
    delete videoProcessor;
}

void VideoPlayer::on_actionVideodatei_ffnen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
        videoThread->openFile(fileName);
     }
}

void VideoPlayer::on_actionKamera_ffnen_triggered()
{
    videoThread->openCamera();
}

void VideoPlayer::on_actionPlay_triggered()
{
    videoThread->start();
}

void VideoPlayer::on_horizontalSlider_valueChanged(int value)
{
    videoProcessor->setThreshold(value);
}
