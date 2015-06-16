//
// Created by toramisu on 2015/6/16.
//

#include "TrackToolBar.h"
#include "model/TrackModel.h"
static void someFunction() {
//    qDebug() << "pressed";
    printf("click me");
}
void TrackToolBar::onClkNewTrackBtn() {
    printf("pressed");

}

TrackToolBar::TrackToolBar(QWidget *parent):QWidget(parent)
{
    resize(250, 25);
    newTrackButton = new QPushButton("new Track",this);
//    QObject::connect(newTrackButton, &QPushButton::clicked, someFunction);
//    newTrackButton->mouseMoveEvent
    connect(newTrackButton, &QPushButton::clicked, [=](int result) {
        printf("click me");

    });
//    this.pressed.connect(someFunction);
//    this->onClkNewTrackBtn();
}

