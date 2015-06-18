//
// Created by manoyuria on 2015/6/18.
//

#include "TimestampBar.h"

TimestampBar::TimestampBar(QWidget *parent) : QWidget(parent) {

}

void TimestampBar::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    QPen pen(QColor(0x343434));
    p.setPen(pen);
    for (int i = 0; i < this->width(); i += TIMELINE_TRACK_FRAME_MAX_WIDTH) {
        p.drawLine(i, 15, i, this->height());
    }
}
