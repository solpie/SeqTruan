//
// Created by manoyuria on 2015/6/18.
//

#include "TrackCursor.h"

TrackCursor::TrackCursor(QWidget *parent) : DragWidget(parent) {
    resize(60, 200);
//    exPressFunc = [] {
//        qDebug() << "press me";
//    };
    timeLabel = new QLabel("00:00:24",this);
    timeLabel->move(2, 10);
//    timeLabel->resize(60, 20);
    setMouseTransparent(this);

}