#ifndef COLORKEYERHSV_H
#define COLORKEYERHSV_H

#include <QMainWindow>
#include <QImage>
#include "videoprocessor.h"

class ColorKeyerHSV : public VideoProcessor {
public:
    ColorKeyerHSV();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);
    void setHueUpperThreshold(int);
    void setHueLowerThreshold(int);
    void setSaturationThreshold(int);
    void setAlpha(float alpha);
    void setMedianEnable(bool enable);
    void setOpeningEnable(bool enable);
private:
    void drawCross(cv::Mat& mat, cv::Point center, int length, cv::Scalar color);
    void centerOfMass(cv::Mat& image);
    cv::Mat colorKeying(cv::Mat& hsvFrame);
public:
    cv::Point center;
private:
    //cv::Point center;
    int hueUpperThreshold;
    int hueLowerThreshold;
    int saturationThreshold;
    float alpha;
    bool useMedian;
    bool useOpening;  
};

#endif // COLORKEYERHSV_H
