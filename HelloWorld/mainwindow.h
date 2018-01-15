#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>

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
    void on_action_ffnen_triggered();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    void createImage(cv::Mat& image);
    void showImage(const cv::Mat& image);

    void process();
    cv::Mat sourceImage;
    cv::Mat destinationImage;
};

#endif // MAINWINDOW_H
