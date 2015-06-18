//
// Created by toramisu on 2015/6/16.
//

#include <model/App.h>
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
//    TrackModel *t = TrackModel::_();
//    t->newTrack();
    App()._().trackModel->newTrack("curry","D:/projects/SeqTruanCpp/test/test10/");
    connect(newTrackButton, &QPushButton::clicked, []{
        printf("click me");
        Evt_dis("type");
    });
//    this.pressed.connect(someFunction);
//    this->onClkNewTrackBtn();
}

