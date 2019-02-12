#ifndef IMAGEFRAME_H
#define IMAGEFRAME_H

#include <QWidget>
#include <QPushButton>
#include <opencv2/core.hpp>

namespace Ui {
class ImageFrame;
}

class ImageFrame : public QWidget {
    Q_OBJECT

public:
    explicit ImageFrame(QWidget *parent = nullptr);
    ~ImageFrame();

private:
    Ui::ImageFrame *ui;
    QString m_fullname;
    QStringList m_files; //list of all files
    QString m_path;      //absolute path
    QPixmap m_picture;   //pixmap of chosen pic
    QString m_fileName;  //filename w/o path to it
    QImage m_outputImage; //пойдет в пиксмап на лейбл
    QPixmap m_outPixmap;
    int m_position = 0;
    int m_degree = 0;
    void cvToLabel(const cv::Mat& frame);
    cv::Mat rotate(cv::Mat src, double angle);
public slots:

    void setFrame(void);
    void changePicture(void);
    void processPicture(void);
    void savePicture(void);
};

#endif // IMAGEFRAME_H
