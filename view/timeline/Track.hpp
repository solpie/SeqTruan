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
    Track(TrackInfo *trackInfo = nullptr) {
//        _trackInfo = trackInfo;
        resize(1280, TIMELINE_TRACK_DEF_HEIGHT);
//    this->setStyleSheet("background:#343434");
        trackFrameArea = new QWidget(this);
        _setX(trackFrameArea, App()._().trackModel->frameWidth);
        trackFrameArea->resize(80, 75);

        headButton = new OverWidget<QWidget>(this);
        headButton->resize(10, 40);
        _setX(headButton, 31);
        headButton->setStyleSheet("border:none");
        over(headButton, paintEvent_, paintHead);

        tailButton = new OverWidget<QWidget>(this);
        tailButton->resize(10, 40);
        tailButton->move(80, 0);
        over(tailButton, paintEvent_, paintTail);
    }

    Track(QWidget *parent) : QWidget(parent) {
        Track();
    }

    void load(TrackInfo *trackInfo) {
        _trackInfo = trackInfo;
        int len = trackInfo->trackFrameInfos->size();
        TrackFrame *pre = nullptr;
        int fw = App()._().trackModel->frameWidth;
        for (int i = 0; i < len; i++) {
            TrackFrameInfo *trackFrameInfo = trackInfo->trackFrameInfos->at(i);
            TrackFrame *trackFrame = new TrackFrame(trackFrameArea);
            trackFrame->setTrackFrameInfo(trackFrameInfo);

            pre = trackFrame->setPre(pre);
            trackFrame->setPixmap(trackFrameInfo->payLoad);
            trackFrame->setIdx(i);
            trackFrame->move(i * fw, 0);
        }
        _setWidth(trackFrameArea, (len) * fw);
        _setX(tailButton, trackFrameArea->x() + trackFrameArea->width());
    }

protected:
    QWidget *trackFrameArea;
    OverWidget<QWidget> *headButton;
    TrackInfo *_trackInfo;
    OverWidget<QWidget> *tailButton;
private:
    void paintHead(void *e) {
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

    void paintTail(void *e) {
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

    bool isPress;
    int _lastX = -1;

    virtual void mousePressEvent(QMouseEvent *mouseEvent) override {
        isPress = true;
        _lastX = _localPos.x();
    };

    virtual void mouseMoveEvent(QMouseEvent *mouseEvent) override {
        if (isPress) {
            int dx;
            dx = _localPos.x() - _lastX;
            int fw = _app.trackModel->frameWidth;
            int newX = x() + (dx / fw) * fw;
            if (newX >= 0 && newX != x()) {
                _trackInfo->setStartFrame((newX / fw) + 1);
                qDebug() << this << "setStartFrame" << _trackInfo->getStartFrame();
                _setX(this, newX);
                _app.trackModel->sequencePlayback->update();
            }
        }
    };

    virtual void mouseReleaseEvent(QMouseEvent *mouseEvent) override {
        isPress = false;

    };
};


#endif //SEQTRUAN_TRACK_H
