#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"
#include "colorkeyerhsv.h"
#include "midioutput.h"

namespace Ui {
class VideoPlayer;
}

class VideoPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();

private slots:
    void on_actionAdd_Camera_triggered();
    void on_actionAdd_Camera_2_triggered();
    void on_actionPlay_triggered();
    void updateParameters();
    void updateValues();

    void on_comboBox_activated(const QString &arg1);

    void on_xSlider_valueChanged(int value);

    void on_ySlider_valueChanged(int value);

    void on_zSlider_valueChanged(int value);

private:
    Ui::VideoPlayer *ui;
    drumstick::rt::MIDIOutput midiOutput;
    int midichannel;
    VideoEngine *videoThread;
    VideoEngine *videoThread2;
    ColorKeyerHSV* colorKeyerHSV;
    ColorKeyerHSV* colorKeyerHSV2;
    void setThresholds();
    void setupMidi(int value);
};

#endif // VIDEOPLAYER_H
