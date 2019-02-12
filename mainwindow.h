#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int count = 0;
   // QPushButton *m_button;


private slots:
//    void pushButtonClicked();
//    void sliderMoved();
};

#endif // MAINWINDOW_H
