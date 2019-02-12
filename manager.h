#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include "mainwindow.h"
#include <QPushButton>
#include <QSlider>
//#include <QProgressBar>
//#include <QLabel>

//#include "slideprogress.h"
#include "actionwidget.h"
#include "imageframe.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPixmap>

class Manager : public QWidget {
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

    QWidget *getWidgets(void);
};

#endif // MANAGER_H
