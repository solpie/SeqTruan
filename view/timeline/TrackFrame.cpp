//
// Created by manoyuria on 2015/6/19.
//

#include "TrackFrame.h"

TrackFrame::TrackFrame(QWidget *parent) : QWidget(parent) {
    resize(40, 60);




//    self.leftButton = QPushButton(self)
//    self.isPressLeftButton = False
//    self.leftButton.resize(8, 8)
//    setStyle(self.leftButton, ':qss_button', 'frameButton')
//    self.leftButton.mousePressEvent = self.onPressLeftButton
//    self.leftButton.mouseReleaseEvent = self.onRels

//
    thumb = new OverWidget<QWidget>(this);
    thumb->resize(40, 50);
    over(thumb, paintEvent_, paintThumb);
    _setMouseTransparent(thumb);


    frameIdx = new QLabel(this);
    frameIdx->setStyleSheet("color:#b6b6b6;border:none;");
    _setMouseTransparent(frameIdx);
    frameIdx->move(4, 45);
    frameIdx->setText("0");


    leftButton = new OverWidget<QPushButton>(this);
    leftButton->resize(8, 8);
    leftButton->isCustomQss = true;
    leftButton->add(mousePressEvent_, [this] { qDebug() << this << "leftButton"; });
    UI::setQss(leftButton, ":/qss_button","frameButton");


    rightButton = new OverWidget<QPushButton>(this);
    rightButton->resize(8, 8);
    rightButton->isCustomQss = true;
    rightButton->add(mousePressEvent_, [this] { qDebug() << this << "leftButton"; });
    UI::setQss(rightButton, ":/qss_button","frameButton");


//    self.rightButton = QPushButton(self)
//    self.isPressRightButton = False
//    setStyle(self.rightButton, ':qss_button', 'frameButton')
//    self.rightButton.resize(8, 8)
//    self.rightButton.move(33, 32)
//    self.rightButton.mousePressEvent = self.onPressRightButton
//    self.rightButton.mouseReleaseEvent = self.onRels
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

    QPainter pm(this->thumb);
    if (this->thumbPixmap != NULL) {
        pm.drawPixmap(int((this->width() - this->thumbPixmap->width() - 2) * .5),
                      int((22 - this->thumbPixmap->height()) * .5 + 9),
                      *this->thumbPixmap);
    }
}

void TrackFrame::setPixmap(QImage *qImage) {
    int thumbHeight = int(float(qImage->height()) / qImage->width() * (this->width() - 2));
    thumbPixmap = new QPixmap(QPixmap::fromImage(qImage->scaled(this->width() - 2, thumbHeight, Qt::KeepAspectRatio)));
}
