//
// Created by manoyuria on 2015/6/18.
//
#pragma once
#ifndef SEQTRUAN_TRACKCURSOR_H
#define SEQTRUAN_TRACKCURSOR_H

#include <QtWidgets/qlabel.h>
#include "view/UI.hpp"

class TrackCursor : public DragWidget {
Q_OBJECT
public:
    TrackCursor(QWidget *parent=0) : DragWidget(parent) {
        resize(60, 200);
        exPressFunc = [] {
//        qDebug() << "press me";
            printf("dd");
        };
        timeLabel = new QLabel("00:00:24", this);
        timeLabel->move(2, 10);
//    timeLabel->resize(60, 20);
//    setMouseTransparent(this);

    }

private:
    QLabel *timeLabel;
    int i;
protected:
    virtual void paintEvent(QPaintEvent *qPaintEvent) override{
        QPainter p(this);
        QPen pen;
        pen.setColor(QColor(TIMELINE_CURSOR_EDGE_COL));

        p.setPen(pen);
        p.drawLine(0, 0, 0, this->height());
        p.drawLine(TIMELINE_TRACK_FRAME_MAX_WIDTH, 0, TIMELINE_TRACK_FRAME_MAX_WIDTH, this->height());
//    QWidget::paintEvent( < unnamed >);
    }
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

