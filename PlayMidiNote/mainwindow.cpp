#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList connections = midiOutput.connections(true);
    ui->comboBox->addItems(connections);
    midiOutput.open("Microsoft GS Wavetable Synth");
    midichannel = ui->midichannel->value();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_pressed(){midiOutput.sendNoteOn(midichannel, 60, 127);}
void MainWindow::on_pushButton_released(){midiOutput.sendNoteOff(midichannel, 60, 0);}
void MainWindow::on_pushButton_2_pressed(){midiOutput.sendNoteOn(midichannel, 61, 127);}
void MainWindow::on_pushButton_2_released(){midiOutput.sendNoteOff(midichannel, 61, 0);}
void MainWindow::on_pushButton_3_pressed(){midiOutput.sendNoteOn(midichannel, 62, 127);}
void MainWindow::on_pushButton_3_released(){midiOutput.sendNoteOff(midichannel, 62, 0);}
void MainWindow::on_pushButton_4_pressed(){midiOutput.sendNoteOn(midichannel, 63, 127);}
void MainWindow::on_pushButton_4_released(){midiOutput.sendNoteOff(midichannel, 63, 0);}
void MainWindow::on_pushButton_5_pressed(){midiOutput.sendNoteOn(midichannel, 64, 127);}
void MainWindow::on_pushButton_5_released(){midiOutput.sendNoteOff(midichannel, 64, 0);}
void MainWindow::on_pushButton_6_pressed(){midiOutput.sendNoteOn(midichannel, 65, 127);}
void MainWindow::on_pushButton_6_released(){midiOutput.sendNoteOff(midichannel, 65, 0);}
void MainWindow::on_pushButton_7_pressed(){midiOutput.sendNoteOn(midichannel, 66, 127);}
void MainWindow::on_pushButton_7_released(){midiOutput.sendNoteOff(midichannel, 66, 0);}
void MainWindow::on_pushButton_8_pressed(){midiOutput.sendNoteOn(midichannel, 67, 127);}
void MainWindow::on_pushButton_8_released(){midiOutput.sendNoteOff(midichannel, 67, 0);}
void MainWindow::on_pushButton_9_pressed(){midiOutput.sendNoteOn(midichannel, 68, 127);}
void MainWindow::on_pushButton_9_released(){midiOutput.sendNoteOff(midichannel, 68, 0);}
void MainWindow::on_pushButton_10_pressed(){midiOutput.sendNoteOn(midichannel, 69, 127);}
void MainWindow::on_pushButton_10_released(){midiOutput.sendNoteOff(midichannel, 69, 0);}
void MainWindow::on_pushButton_11_pressed(){midiOutput.sendNoteOn(midichannel, 70, 127);}
void MainWindow::on_pushButton_11_released(){midiOutput.sendNoteOff(midichannel, 70, 0);}
void MainWindow::on_pushButton_12_pressed(){
    QByteArray data;
    data.resize(6);
    data[0] = 0xf0; //start byte
    data[1] = 10;
    data[2] = 20;
    data[3] = 42;
    data[4] = 0x2a;
    data[5] = 0xf7; //end byte
    midiOutput.sendSysex(data);}
//void MainWindow::on_pushButton_12_pressed(){midiOutput.sendNoteOn(midichannel, 71, 127);}
void MainWindow::on_pushButton_12_released(){midiOutput.sendNoteOff(midichannel, 71, 0);}

void MainWindow::on_volume_valueChanged(int value)
{
   midiOutput.sendController(midichannel, 7, value);
}

void MainWindow::on_pitchbend_valueChanged(int value)
{
    midiOutput.sendPitchBend(midichannel, value);
}

void MainWindow::on_midichannel_valueChanged(int arg1)
{
    midichannel = arg1;
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    midiOutput.open(arg1);
}

void MainWindow::on_program_valueChanged(int arg1)
{
    midiOutput.sendProgram(midichannel, arg1);
}



