//
// Created by manoyuria on 2015/6/18.
//
#pragma once
#ifndef SEQTRUAN_TRACKCURSOR_H
#define SEQTRUAN_TRACKCURSOR_H

#include <QtWidgets/qlabel.h>
#include "view/UI.h"

class TrackCursor : public DragWidget {
Q_OBJECT
public:
    TrackCursor(QWidget *parent=0);

private:
    QLabel *timeLabel;
    int i;
};
//#include "Qt"
//TrackCursor::TrackCursor(QWidget *parent) : DragWidget(parent) {
//    resize(60, 200);
////    exPressFunc = [] {
////        qDebug() << "press me";
////    };
//    timeLabel = new QLabel("00:00:24");
//    timeLabel->move(2, 10);
//    setMouseTransparent(this);
//
//}

#endif //SEQTRUAN_TRACKCURSOR_H

