//
// Created by manoyuria on 2015/6/18.
//

#include "Track.h"

Track::Track() {
    resize(1280, TIMELINE_TRACK_DEF_HEIGHT);
//    this->setStyleSheet("background:#343434");
}

Track::Track(QWidget *parent) : QWidget(parent) {
    Track();
}

void Track::load(TrackInfo *trackInfo) {
    this->trackInfo = trackInfo;
    headButton = new OverWidget(this);
    headButton->resize(10, 40);
    headButton->move(31 - 9, 0);
    headButton->setStyleSheet("boder:none");
    over(headButton, paintEvent_, paintHead);

    tailButton = new OverWidget(this);
    tailButton->resize(10, 40);
    tailButton->move(80, 0);
    over(tailButton, paintEvent_, paintTail);


}

void Track::paintHead() {
    QPainterPath path;
    int y = 17;
    path.moveTo(9, 0 + y);
    path.lineTo(0, 9 + y);
    path.lineTo(0, 22 + y);
    path.lineTo(9, 22 + y);
    path.lineTo(9, 0 + y);
    path.moveTo(4, 11 + y);
    path.lineTo(4, 11 + y + 6);
    path.moveTo(6, 11 + y);
    path.lineTo(6, 11 + y + 6);
    QPainter p(headButton);
    QPen pen(QColor(0x343434));
    p.setPen(pen);
    p.drawPath(path);
}

void Track::paintTail() {
    QPainterPath path;
    path.moveTo(0, 22);
    path.lineTo(9, 22 - 9);
    path.lineTo(9, 0);
    path.lineTo(0, 0);
    path.lineTo(0, 22);

    path.moveTo(4, 4);
    path.lineTo(4, 4 + 6);
    path.moveTo(6, 4);
    path.lineTo(6, 4 + 6);
    QPainter p(tailButton);
    QPen pen(QColor(0x343434));
    p.setPen(pen);
    p.drawPath(path);
}
