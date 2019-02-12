#include "imageframe.h"
#include "ui_imageframe.h"
#include "actionwidget.h"
#include <QDebug>
#include <QFileDialog>
#include <QSlider>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QMessageBox>
#include <QFileDialog>
using namespace cv;

ImageFrame::ImageFrame(QWidget *parent) : QWidget(parent), ui(new Ui::ImageFrame) {
    ui->setupUi(this);

}

ImageFrame::~ImageFrame() {
    delete ui;
}

void ImageFrame::cvToLabel(const cv::Mat& frame) {
    if(frame.channels() == 3) {
        m_outputImage = QImage(frame.data,frame.cols,frame.rows,static_cast<int>(frame.step),QImage::Format_RGB888);
    } else {
        m_outputImage = QImage(frame.data, frame.cols,frame.rows, static_cast<int>(frame.step),QImage::Format_Indexed8);
    }

    if (!m_outputImage.isNull()) {
       m_outPixmap = QPixmap::fromImage(m_outputImage);
       ui->pictureLabel->setAlignment(Qt::AlignCenter);
       ui->pictureLabel->setPixmap(m_outPixmap.scaled(ui->pictureLabel->size(),
                                                                              Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}

void ImageFrame::setFrame() {
    qDebug() << "Pushed";
    m_fullname = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), ".",
                                                    tr("Image Files (*.png *.bmp *.jpg)"));

    m_path = QString(QFileInfo(m_fullname).absolutePath()) + "/"; //folder where pic is located


    m_picture = m_fullname; //QPixmap
    ui->pictureLabel->setAlignment(Qt::AlignCenter);
    ui->pictureLabel->setPixmap(m_picture);
    QDir directory(m_path);
    m_files = directory.entryList(QStringList() << "*.jpg" << "*.JPG" <<"*.png"<<"*.bmp",QDir::Files);
    QFile link(m_fullname);
    QFileInfo link2(link.fileName());
    m_fileName = link2.fileName();
    for (int i = 0; i < m_files.length(); ++i) {
        if (QString(m_files[i]) == m_fileName) {
            m_position = i;
        }
    }
    qDebug() << m_files[0] << m_fileName << m_position << m_files.length();
}

void ImageFrame::changePicture() {
    qDebug() << "connect ok";
    QPushButton *button; // чекаем нажатую кнопку - прев - некст
    QString buttonVal;
    button = qobject_cast<QPushButton*>(sender()); /* Возвращает указатель на нажатую кнопку */
    if (!(m_path.isEmpty())) {
        if (button){
            buttonVal = button->text();
            if (buttonVal == "<< Previous") {
                qDebug() << "Previous" << m_files.length();
                if (m_position == 0) {
                    m_picture = m_path + m_files[m_files.length()-1];

                    ui->pictureLabel->setPixmap(m_picture);
                    m_position = m_files.length()-1;
                } else{
                    m_position--;
                    m_picture = m_path + m_files[m_position];
                    ui->pictureLabel->setPixmap(m_picture);
                }
            }
            else if (buttonVal == "Next >>") {
                qDebug() << "Next" << m_files.length();
                if (m_position == m_files.length()-1){
                    m_picture = m_path + m_files[0];
                    ui->pictureLabel->setPixmap(m_picture);
                    m_position = 0;
                } else{
                    m_position++;
                    m_picture = m_path + m_files[m_position];
                    m_fullname = m_path + m_files[m_position];
                    ui->pictureLabel->setPixmap(m_picture);
                }
            }
            m_fullname = m_path + m_files[m_position];
        }
    }
}

void ImageFrame::processPicture() {
    QSlider *slider; // чекаем нажатую кнопку - прев - некст
    slider = qobject_cast<QSlider*>(sender());
    qDebug() << slider->value();
//    QString degree = QString::number(slider->value());
//    if (!degree.isEmpty()){
//        m_degree = slider->value();
//    }
//    else {
//        m_degree = rand() % 360 + (-180);
//    }
    if (!m_fullname.isEmpty()) {
        //CV_LOAD_IMAGE_GRAYSCALE , CV_LOAD_IMAGE_COLOR
        cv::Mat m_frame = cv::imread(m_fullname.toStdString());
        if(!m_frame.data) {
            QMessageBox msgBox;
            msgBox.setText("The selected image could not be opened!");
            msgBox.exec();
        } else {
            if (m_frame.channels() == 3)
              cvtColor(m_frame, m_frame, CV_BGR2RGB);
              cv::Point2f pt(m_frame.cols/2, m_frame.rows/2);
              cv::Mat r = getRotationMatrix2D(pt, slider->value(), 1.0); //второй аргумент в скобках - угол поворота
              warpAffine(m_frame, m_frame, r, cv::Size(m_frame.cols, m_frame.rows));
              cvToLabel(m_frame);
        }
    }
}

void ImageFrame::savePicture() {
    qDebug() << "save connect";
    QString filter = "png(*png);;jpg(*jpg);;bmp(*bmp)";
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Image"), ".",
                                                    filter);
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)) {
        m_outPixmap.save(&file, 0, -1);
        file.close();
    } else {
        QMessageBox msgBox;
        msgBox.setText("Can't save file!");
        msgBox.exec();
    }
}


