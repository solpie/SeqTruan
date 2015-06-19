//
// Created by manoyuria on 2015/6/19.
//

#include "TrackFrame.h"

TrackFrame::TrackFrame(QWidget *parent) : QWidget(parent) {
    thumb = new OverWidget(this);
    thumb->resize(40, 50);
    over(thumb, paintEvent_, paintThumb);
    _setMouseTransparent(thumb);
}

void TrackFrame::paintThumb() {
    QPainter pg(this->thumb);
    QLinearGradient lg(0, 0, 0, 38);
    lg.setColorAt(0.0, QColor(0x343434));
    lg.setColorAt(0.5, QColor(0x606060));
    lg.setColorAt(1.0, QColor(0x343434));
    pg.setBrush(QBrush(lg));
    pg.drawRect(0, 2, width(), 36);
    QPainter p(this->thumb);
    QPen pen(QColor(0xc8c8c8));
    p.setPen(pen);
    p.drawLine(0, 1, this->thumb->width(), 1);
    p.drawLine(0, this->thumb->height() - 2 - 10, this->thumb->width(), this->thumb->height() - 2 - 10);
    p.fillRect(0, 9, TIMELINE_TRACK_FRAME_MAX_WIDTH, 22, QColor(0xffffff));
    pen.setColor(QColor(0x343434));
    p.setPen(pen);
    p.drawLine(0, this->thumb->height() - 1 - 10, this->thumb->width(), this->thumb->height() - 1 - 10);
    p.drawLine(0, 0, 0, this->thumb->height());
    p.drawLine(0, 0, this->thumb->width(), 0);
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

//void TrackFrame::setPixmap(QPixmap *pixmap) {
void TrackFrame::setPixmap(QImage *pixmap) {
//    self.thumbWidth = img.width()
//    self.thumbHeight = img.height() / img.width() * (self.width() - 3)
//    self.thumbPixmap = img.scaled(self.width(), self.thumbHeight)
    thumbWidth = pixmap->width();
    thumbHeight = pixmap->height() / pixmap->width() * (this->width() - 3);
    thumbPixmap = QPixmap::fromImage(pixmap->scaled(this->width(), thumbHeight));

}
