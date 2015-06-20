//
// Created by manoyuria on 2015/6/18.
//

#include "Track.h"

Track::Track() {
    resize(1280, TIMELINE_TRACK_DEF_HEIGHT);
//    this->setStyleSheet("background:#343434");
    trackFrameArea = new QWidget(this);
    trackFrameArea->move(TIMELINE_TRACK_FRAME_MAX_WIDTH - 9, 0);
    trackFrameArea->resize(80, 75);

    headButton = new OverWidget<QWidget>;
    headButton->resize(10, 40);
    headButton->move(31 - 9, 0);
    headButton->setStyleSheet("border:none");
    headButton->setParent(this);
    over(headButton, paintEvent_, paintHead);

    tailButton = new OverWidget<QWidget>;
    tailButton->resize(10, 40);
    tailButton->move(80, 0);
    tailButton->setParent(this);
    over(tailButton, paintEvent_, paintTail);
}

Track::Track(QWidget *parent) : QWidget(parent) {
    Track();
}

void Track::load(TrackInfo *trackInfo) {
    this->trackInfo = trackInfo;

    int len = trackInfo->frames.size();
    for (int i = 0; i < len; i++) {
        TrackFrameInfo *trackFrameInfo = trackInfo->frames[i];
        TrackFrame *trackFrame = new TrackFrame(trackFrameArea);
        trackFrame->setPixmap(trackFrameInfo->payLoad);
        trackFrame->idx = i + 1;
        trackFrame->move(i * TIMELINE_TRACK_FRAME_MAX_WIDTH, 0);
    }
    _setWidth(trackFrameArea, (len + 1) * TIMELINE_TRACK_FRAME_MAX_WIDTH);
    _setX(tailButton,tailButton->width()+trackFrameArea->width()-TIMELINE_TRACK_FRAME_MAX_WIDTH);
//    trackFrame.setPixmap(sImage.getPixmap())

//    trackFrame.setIdx(i + 1)
//    trackFrame.trackIdx = self.trackIdx
//    trackFrame.relayout = self.relayout
//    trackFrame.move(i * trackFrame.width(), 0)
//    trackFrame.refSImage = sImage
//    self.thumbArr.append(trackFrame)
//    self.trackFrameArea.resize((len(self.thumbArr) + 1) * TIMELINE_TRACK_FRAME_MAX_WIDTH,
//                               self.trackFrameArea.height())
//    self.tailButton.move(self.trackFrameArea.x() + self.trackFrameArea.width() - TIMELINE_TRACK_FRAME_MAX_WIDTH,
//                         0)

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
