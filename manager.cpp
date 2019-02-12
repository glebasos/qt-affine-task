#include "manager.h"

Manager::Manager(QWidget *parent) : QWidget(parent)
{

}
QWidget *Manager::getWidgets(void) {
    QPushButton* buttonOpen;
    QPushButton* buttonPrev;
    QPushButton* buttonNext;
    QPushButton* buttonProc;
    QPushButton* buttonSave;
    QSlider *sliderRotate;

    QVBoxLayout *combLayout = new QVBoxLayout(); // Главный лэйаут для компановки виджета
    QVBoxLayout *pictureLayout = new QVBoxLayout(); // Лэйаут картинки
    QGridLayout *actionLayout = new QGridLayout(); // Лэйаут кнопок процессинга

    QWidget *combWidget = new QWidget(this); // Виджет, в котором происходит компановка других виджетов

    ImageFrame *picFrame = new ImageFrame(this); // Виджет пикчи
    ActionWidget *actWidget = new ActionWidget(this); //Виджет кнопок

    pictureLayout->addWidget(picFrame);
    actionLayout->addWidget(actWidget);

    combLayout->addLayout(pictureLayout);
    combLayout->addLayout(actionLayout);
    combWidget->setLayout(combLayout);

    buttonOpen = actWidget->findChild<QPushButton*>("openButton");
    buttonPrev = actWidget->findChild<QPushButton*>("prevButton");
    buttonNext = actWidget->findChild<QPushButton*>("nextButton");
    buttonProc = actWidget->findChild<QPushButton*>("procButton");
    buttonSave = actWidget->findChild<QPushButton*>("saveButton");
    sliderRotate = actWidget->findChild<QSlider*>("degreeSlider");
    connect(buttonOpen, SIGNAL(released()), picFrame, SLOT(setFrame() ));
    connect(buttonPrev, SIGNAL(released()), picFrame, SLOT(changePicture() ));
    connect(buttonNext, SIGNAL(released()), picFrame, SLOT(changePicture() ));
    connect(buttonSave, SIGNAL(released()), picFrame, SLOT(savePicture() ));
    connect(sliderRotate, SIGNAL(valueChanged(int)	), picFrame, SLOT(processPicture() ));

    return combWidget;
}

Manager::~Manager() {

}
