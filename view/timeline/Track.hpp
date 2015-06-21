#pragma once
//
// Created by manoyuria on 2015/6/18.
//

#ifndef SEQTRUAN_TRACK_H
#define SEQTRUAN_TRACK_H

#include "view/UI.hpp"
#include "model/App.hpp"

#include "TrackFrame.hpp"

class Track : public QWidget {
public:
    Track() {
        resize(1280, TIMELINE_TRACK_DEF_HEIGHT);
//    this->setStyleSheet("background:#343434");
        trackFrameArea = new QWidget(this);
        trackFrameArea->move(TIMELINE_TRACK_FRAME_MAX_WIDTH - 9, 0);
        trackFrameArea->resize(80, 75);

        headButton = new OverWidget<QWidget>(this);
        headButton->resize(10, 40);
        headButton->move(31 - 9, 0);
        headButton->setStyleSheet("border:none");
//    headButton->setParent(this);
        over(headButton, paintEvent_, paintHead);

        tailButton = new OverWidget<QWidget>(this);
        tailButton->resize(10, 40);
        tailButton->move(80, 0);
//    tailButton->setParent(this);
        over(tailButton, paintEvent_, paintTail);
    }

    Track(QWidget *parent) : QWidget(parent) {
        Track();
    }

    void load(int tIdx) {
        TrackInfo *trackInfo = App()._().trackModel->getTrackInfo(tIdx);
        trackInfoIdx = tIdx;
        int len = trackInfo->trackFrameInfos->size();
        TrackFrame *pre = NULL;
        for (int i = 0; i < len; i++) {
            TrackFrameInfo *trackFrameInfo = trackInfo->trackFrameInfos->at(i);
//        TrackFrameInfo *trackFrameInfo = trackInfo->trackFrameInfos[i];
            TrackFrame *trackFrame = new TrackFrame(trackFrameArea);
            if (pre != NULL) {
                trackFrame->pre = pre;
                pre->next = trackFrame;
            }
            pre = trackFrame;


//            trackFrame->trackInfoIdx = trackInfo->idx;

//            trackFrame->trackFrameInfoIdx = trackFrameInfo->idx;
            trackFrame->setPixmap(trackFrameInfo->payLoad);

            trackFrameInfo->startFrameIdx = i + 1;
            trackFrameInfo->endFrameIdx = i+1;
            trackFrame->setIdx(i);

            trackFrame->move(i * TIMELINE_TRACK_FRAME_MAX_WIDTH, 0);
        }
        _setWidth(trackFrameArea, (len + 1) * TIMELINE_TRACK_FRAME_MAX_WIDTH);
        _setX(tailButton, tailButton->width() + trackFrameArea->width());
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

    int trackInfoIdx = 0;

//    TrackInfo *trackInfo;
    void paintHead() {
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

    OverWidget<QWidget> *headButton;

    void paintTail() {
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

    OverWidget<QWidget> *tailButton;
private:
    vector<TrackFrame *> *trackFrames;
    QWidget *trackFrameArea;
};


#endif //SEQTRUAN_TRACK_H
