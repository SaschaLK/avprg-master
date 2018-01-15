#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "midioutput.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_volume_valueChanged(int value);

    void on_pitchbend_valueChanged(int value);

    void on_midichannel_valueChanged(int arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_program_valueChanged(int arg1);



    void on_pushButton_pressed();
    void on_pushButton_released();
    void on_pushButton_2_pressed();
    void on_pushButton_2_released();
    void on_pushButton_3_pressed();
    void on_pushButton_3_released();
    void on_pushButton_4_pressed();
    void on_pushButton_4_released();
    void on_pushButton_5_pressed();
    void on_pushButton_5_released();
    void on_pushButton_6_pressed();
    void on_pushButton_6_released();
    void on_pushButton_7_pressed();
    void on_pushButton_7_released();
    void on_pushButton_8_pressed();
    void on_pushButton_8_released();
    void on_pushButton_9_pressed();
    void on_pushButton_9_released();
    void on_pushButton_10_pressed();
    void on_pushButton_10_released();
    void on_pushButton_11_pressed();
    void on_pushButton_11_released();
    void on_pushButton_12_pressed();
    void on_pushButton_12_released();

private:
    Ui::MainWindow *ui;
    drumstick::rt::MIDIOutput midiOutput;
    int midichannel;
};

#endif // MAINWINDOW_H
