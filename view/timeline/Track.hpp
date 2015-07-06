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
Q_OBJECT
public:
    Track(TrackInfo *trackInfo = nullptr) {
//        _trackInfo = trackInfo;
        resize(100, TIMELINE_TRACK_DEF_HEIGHT);
//    this->setStyleSheet("background:#343434");
        trackFrameArea = new QWidget(this);
        trackFrameArea->resize(80, 75);

        headButton = new OverWidget<QWidget>(this);
        headButton->resize(10, 40);
        UI::setX(headButton, 30);
        headButton->setStyleSheet("border:none");
        over(headButton, paintEvent_, paintHead);
        UI::setX(trackFrameArea, headButton->x() + headButton->width());

        tailButton = new OverWidget<QWidget>(this);
        tailButton->resize(10, 40);
        UI::setX(tailButton, 80);
        over(tailButton, paintEvent_, paintTail);

//        setObjectName("track");
//        setStyleSheet("QWidget#track{border-width: 1px;border-style: solid;border-bottom-color: #343434;}");
        QPalette bgpal = palette();
//        bgpal.setColor(QPalette::Background, QColor(0, 0, 0, 255));
        bgpal.setColor(QPalette::Background, Qt::transparent);
//        bgpal.setColor(QPalette::Foreground, QColor(255, 255, 255, 255));
        setPalette(bgpal);


        Evt_add(TrackModelEvent::SET_ZOOM_LEVEL, onUpdateZoom);
    }

    Track(QWidget *parent) : QWidget(parent) {
        Track();
    }

    void load(TrackInfo *trackInfo) {
        _trackInfo = trackInfo;
        int len = trackInfo->trackFrameInfos->size();
        TrackFrame *pre = nullptr;
        int fw = _app.trackModel->frameWidth;
        for (int i = 0; i < len; i++) {
            TrackFrameInfo *trackFrameInfo = trackInfo->trackFrameInfos->at(i);
            TrackFrame *trackFrame = new TrackFrame(trackFrameArea);
            if (headTrackFrame == nullptr) {
                //todo 第一帧修改
                headTrackFrame = trackFrame;
            }
            trackFrame->setTrackFrameInfo(trackFrameInfo);

            pre = trackFrame->setPre(pre);
//            trackFrame->setPixmap(trackFrameInfo->payLoad);
            trackFrame->setIdx(i);
            trackFrame->move(i * fw, 0);
            connect(trackFrame, trackFrame->resizeTail, [=] { this->resizeTrackByFrameCount(); });
        }
        resizeTrackByFrameCount();
    }

signals:

    void resizeTrack(int width);

protected:
    OverWidget<QWidget> *headButton;
    TrackInfo *_trackInfo;
    OverWidget<QWidget> *tailButton;
private:
    TrackFrame *headTrackFrame = nullptr;
    QWidget *trackFrameArea;

    void onUpdateZoom(void *e) {
        resizeTrackFrame(headTrackFrame,0);
        resizeTrackByFrameCount();
    }

    void resizeTrackFrame(TrackFrame *tf,int px) {
        tf->updateFrameWidth();
        UI::setX(tf, px);
        if (tf->next)
            resizeTrackFrame(tf->next,tf->x()+tf->width());

    }

    void resizeTrackByFrameCount() {
        int fw = _app.trackModel->frameWidth;
        int len = _trackInfo->getFrameCount();
        UI::setWidth(trackFrameArea, (len) * fw);
        UI::setX(tailButton, trackFrameArea->x() + trackFrameArea->width());
        UI::setWidth(this, tailButton->x() + tailButton->width());
        emit resizeTrack(width());
    }

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
        _lastX = mouseEvent->pos().x();
    };

    virtual void mouseMoveEvent(QMouseEvent *mouseEvent) override {
        if (isPress) {
            int dx;
//            int px = mapToParent(QCursor::pos()).x();
            int px = mapToParent(mouseEvent->pos()).x();
            qDebug() << this << "posx" << mouseEvent->pos().x() << "mapToParent" << px;
            dx = mouseEvent->pos().x() - _lastX;
//            _lastX = mouseEvent->pos().x();
            int drag = 20;
            if (abs(dx) > drag) {
                int fw = _app.trackModel->frameWidth;
//            dx = _localPos.x() - _lastX + (fw - TIMELINE_DRAG_WIDTH);
                int newX = x() + ceil(dx / fw) * fw;
//                qDebug() << this << "setStartFrame" << _trackInfo->getStartFrame()
//                << "x()" << x() << "width()" << width();
                int dtWidth = newX - x();

                if (newX >= 0 && newX != x()) {
                    _trackInfo->setStartFrame((newX / fw) + 1);
//                    qDebug() << this << "setStartFrame" << _trackInfo->getStartFrame()
//                    << "x()" << x() << "width()" << width();

                    int endWidth = _trackInfo->getFrameCount() * fw + TIMELINE_HANDLE_BUTTON_WIDTH;
                    UI::setWidth(this, endWidth);
                    int endPosX = x() + endWidth;
                    if (_app.trackModel->trackWidth < endPosX) {
                        _app.trackModel->trackWidth = endPosX;
                        Evt_dis(TrackModelEvent::MOVE_TRACK, nullptr);
                    }
                    UI::setX(this, newX);
                    _app.trackModel->sequencePlayback->update();
                }
            }
        }
    };

    virtual void mouseReleaseEvent(QMouseEvent *mouseEvent) override {
        isPress = false;
    };
};


#endif //SEQTRUAN_TRACK_H
