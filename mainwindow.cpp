#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QProgressBar>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Manager *manager = new Manager(this);
    ui->gridLayout->addWidget(manager->getWidgets());

}

MainWindow::~MainWindow()
{
    delete ui;
}


