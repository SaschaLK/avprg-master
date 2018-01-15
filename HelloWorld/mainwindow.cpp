#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

#include <opencv2/opencv.hpp>
#include "cvmattoqimage.h"
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // leeres Bild definieren
    Mat image(400, 400, CV_8UC3);
    createImage(image);
    showImage(image);

 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createImage(Mat &image){
    // Rechteck zeichnen
    Point linksOben(10, 30);
    Point rechtsUnten(200, 300);
    Scalar color(0, 100, 200);
    rectangle(image, linksOben, rechtsUnten, color, CV_FILLED);
}

void MainWindow::showImage(const Mat &image){
    // Mat Objekt darstellen
    QPixmap pixmap = cvMatToQPixmap(image);
    ui->imageLabel->setPixmap(pixmap);

}

void MainWindow::on_action_ffnen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
       tr("Open File"), "", tr("Images (*.png, *.jpg)"));
    sourceImage = imread(filename.toStdString());

    destinationImage = sourceImage.clone();
    process();
    showImage(destinationImage);
}

void MainWindow::process(){
    for(int x = 0; x < sourceImage.cols; x++){
        for(int y = 0; y < sourceImage.rows; y++){
            Vec3b sourcePixel = sourceImage.at<Vec3b>(y,x);
            int b = sourcePixel[0];
            int g = sourcePixel[1];
            int r = sourcePixel[2];

//            r = saturate_cast<uchar>(2 * r);

            int gray = (r + g +b)/3;
            // hier können die Farbwerte manipuliert werden

            //Vec3b destinationPixel(b, g, r);
            Vec3b destinationPixel(gray, gray, gray);
            destinationImage.at<Vec3b>(y,x) = destinationPixel;
        }
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    for(int x = 0; x < sourceImage.cols; x++){
        for(int y = 0; y < sourceImage.rows; y++){
            Vec3b sourcePixel = sourceImage.at<Vec3b>(y,x);
            int b = sourcePixel[0];
            int g = sourcePixel[1];
            int r = sourcePixel[2];


            Vec3b destinationPixel(
                        saturate_cast<uchar>(b + value),
                        saturate_cast<uchar>(g + value),
                        saturate_cast<uchar>(r + value)
            );
            destinationImage.at<Vec3b>(y,x) = destinationPixel;
        }
    }
    showImage(destinationImage);
}
