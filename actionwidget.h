#ifndef ACTIONWIDGET_H
#define ACTIONWIDGET_H

#include <QWidget>

namespace Ui {
class ActionWidget;
}

class ActionWidget : public QWidget {
    Q_OBJECT

public:
    explicit ActionWidget(QWidget *parent = nullptr);
    ~ActionWidget();

private:
    Ui::ActionWidget *ui;
};

#endif // ACTIONWIDGET_H
