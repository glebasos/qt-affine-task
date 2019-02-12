#include "actionwidget.h"
#include "ui_actionwidget.h"

ActionWidget::ActionWidget(QWidget *parent) : QWidget(parent), ui(new Ui::ActionWidget) {
    ui->setupUi(this);
}

ActionWidget::~ActionWidget() {
    delete ui;
}

