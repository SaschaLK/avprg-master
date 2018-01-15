#include "videoplayer.h"
#include "ui_videoplayer.h"
#include <QTimer>

VideoPlayer::VideoPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VideoPlayer),
    videoThread(new VideoEngine),
    videoThread2(new VideoEngine),
    colorKeyerHSV(new ColorKeyerHSV()),
    colorKeyerHSV2(new ColorKeyerHSV())
{
    ui->setupUi(this);
    QStringList connections = midiOutput.connections(true);
    ui->comboBox->addItems(connections);
    midiOutput.open("Microsoft GS Wavetable Synth");
    midichannel = 0;
    videoThread->setProcessor(colorKeyerHSV);
    videoThread2->setProcessor(colorKeyerHSV2);
    connect(videoThread, &VideoEngine::sendInputImage,
            ui->inputFrame, &VideoWidget::setImage);
    connect(videoThread, &VideoEngine::sendProcessedImage,
            ui->outputFrame, &VideoWidget::setImage);
    connect(videoThread2, &VideoEngine::sendInputImage,
            ui->inputFrame_2, &VideoWidget::setImage);
    connect(videoThread2, &VideoEngine::sendProcessedImage,
            ui->outputFrame_2, &VideoWidget::setImage);
    updateParameters();
    updateValues();
}

VideoPlayer::~VideoPlayer() {
    delete videoThread;
    delete videoThread2;
    delete ui;
    delete colorKeyerHSV;
    delete colorKeyerHSV2;
}

void VideoPlayer::on_actionAdd_Camera_triggered() {
    videoThread->openCamera();
}

void VideoPlayer::on_actionAdd_Camera_2_triggered() {
    videoThread2->openCamera(1);
}

void VideoPlayer::on_actionPlay_triggered() {
    videoThread->start();
    videoThread2->start();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateValues()));
    timer->start(1000);
}

void VideoPlayer::updateParameters(){
    //hue + tolerance
    int hueValue = ui->hueSlider->value();
    int toleranceValue = ui->toleranceSilder->value();
    int toleranceMin = hueValue - toleranceValue;
    int toleranceMax = hueValue + toleranceValue;

    if(toleranceMin < 0) toleranceMin += 360;
    if(toleranceMax > 360) toleranceMax -= 360;

    colorKeyerHSV->setHueLowerThreshold(toleranceMin);
    colorKeyerHSV->setHueUpperThreshold(toleranceMax);
    colorKeyerHSV2->setHueLowerThreshold(toleranceMin);
    colorKeyerHSV2->setHueUpperThreshold(toleranceMax);
    ui->hueValue->setNum(hueValue);
    ui->toleranceValue->setNum(toleranceValue);

    //saturation
    int saturationValue = ui->saturationSlider->value();
    colorKeyerHSV->setSaturationThreshold(saturationValue);
    colorKeyerHSV2->setSaturationThreshold(saturationValue);
    ui->saturationValue->setNum(saturationValue);

    //equalizer
    float equalizerValue = ui->equalizerSlider->value();
    colorKeyerHSV->setAlpha(equalizerValue/100.f);
    colorKeyerHSV2->setAlpha(equalizerValue/100.f);
    ui->equalizerValue->setNum(equalizerValue);

    //median
    colorKeyerHSV->setMedianEnable(ui->medianCheck->checkState() == Qt::Checked);
    colorKeyerHSV2->setMedianEnable(ui->medianCheck->checkState() == Qt::Checked);

    //opening
    colorKeyerHSV->setOpeningEnable(ui->openingCheck->checkState() == Qt::Checked);
    colorKeyerHSV2->setOpeningEnable(ui->openingCheck->checkState() == Qt::Checked);
}

void VideoPlayer::updateValues(){
    //X, Y, Z Values for Mesh
    int x = colorKeyerHSV->center.x;
    int y = colorKeyerHSV->center.y;
    int z = colorKeyerHSV2->center.x;

    ui->xValue->setNum(x);
    ui->yValue->setNum(y);
    ui->zValue->setNum(z);

    setupMidi(x);
    setupMidi(y);
    setupMidi(z);
}
void VideoPlayer::setupMidi(int value){
    QByteArray data;
    data.resize(8);
    data[0] = 0xf0;
    data[7] = 0xf7;
    for(int i = 1; i<=6; i++){
        //all pieces one after another
        if(value>127){
            value -= 127;
            data[i] = 127;
        }
        else if(value<=127 && i != 6){
            data[i] = 0;
        }
        else if(i == 6){
            data[6] = value;
        }
    }
    midiOutput.sendSysex(data);
}

void VideoPlayer::on_comboBox_activated(const QString &arg1){
    midiOutput.open(arg1);
}

//temp sliders:
void VideoPlayer::on_xSlider_valueChanged(int value){
    ui->xValue->setNum(value);
    setupMidi(value);
    setupMidi(ui->ySlider->value());
    setupMidi(ui->zSlider->value());
}

void VideoPlayer::on_ySlider_valueChanged(int value){
    ui->yValue->setNum(value);
    setupMidi(ui->xSlider->value());
    setupMidi(value);
    setupMidi(ui->zSlider->value());
}

void VideoPlayer::on_zSlider_valueChanged(int value){
    ui->zValue->setNum(value);
    setupMidi(ui->xSlider->value());
    setupMidi(ui->ySlider->value());
    setupMidi(value);
}
