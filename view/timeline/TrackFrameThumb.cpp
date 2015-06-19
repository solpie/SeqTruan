//
// Created by manoyuria on 2015/6/19.
//

#include "TrackFrameThumb.h"

TrackFrameThumb::TrackFrameThumb(QWidget *parent) : QWidget(parent) {

}

void TrackFrameThumb::paintEvent(QPaintEvent *event) {
    QPainter pg(this);
    QLinearGradient lg(0, 0, 0, 38);
    lg.setColorAt(0.0, QColor(0x343434));
    lg.setColorAt(0.5, QColor(0x606060));
    lg.setColorAt(1.0, QColor(0x343434));
    pg.setBrush(QBrush(lg));
    pg.drawRect(0, 2, width(), 36);
    //todo
//
//    p = QPainter(self.thumb)
//    pen = QPen()
//    col = QColor(0xc8c8c8)
//    pen.setColor(col)
//    p.setPen(pen)
//    p.drawLine(0, 1, self.thumb.width(), 1)
//    p.drawLine(0, self.thumb.height() - 2 - 10, self.thumb.width(), self.thumb.height() - 2 - 10)
//    p.fillRect(0, 9, TIMELINE_TRACK_FRAME_MAX_WIDTH, 22, QColor(0xffffff))
//    pen.setColor(QColor(0x343434))
//    p.setPen(pen)
//    p.drawLine(0, self.thumb.height() - 1 - 10, self.thumb.width(), self.thumb.height() - 1 - 10)
//    p.drawLine(0, 0, 0, self.thumb.height())
//    p.drawLine(0, 0, self.thumb.width(), 0)
//
//    if self.thumbPixmap:
//    B.drawPixmap(self.thumb, self.thumbPixmap, 1, (22 - self.thumbPixmap.height()) * .5 + 9)
//    if self.getIdx() == 1:
//    pass
}
