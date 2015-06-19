//
// Created by manoyuria on 2015/6/18.
//

#include "TrackCursor.h"

TrackCursor::TrackCursor(QWidget *parent) : DragWidget(parent) {
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

void TrackCursor::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    QPen pen;
    pen.setColor(QColor(TIMELINE_CURSOR_EDGE_COL));

    p.setPen(pen);
    p.drawLine(0, 0, 0, this->height());
    p.drawLine(TIMELINE_TRACK_FRAME_MAX_WIDTH, 0, TIMELINE_TRACK_FRAME_MAX_WIDTH, this->height());
//    QWidget::paintEvent( < unnamed >);
}
