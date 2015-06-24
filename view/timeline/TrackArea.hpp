#pragma once
//
// Created by manoyuria on 2015/6/18.
//

#ifndef SEQTRUAN_TRACKAREA_H
#define SEQTRUAN_TRACKAREA_H

#include <model/TrackModel.hpp>
#include "view/UI.hpp"
#include "view/timeline/FrameCursor.hpp"
#include "TimestampBar.hpp"
#include "Track.hpp"

class TrackArea : public QWidget {
public:
    QWidget *trackStack;

    TrackArea(QWidget *parent) : QWidget(parent) {
        timestampBar = new TimestampBar(this);
        timestampBar->resize(1280, 25);


        trackStack = new QWidget(this);
        trackStack->setObjectName("track");
        trackStack->setStyleSheet("QWidget#track{background:#343434;}");
        //todo make local
//    QVBoxLayout *vbox = new QVBoxLayout(trackStack);
        vbox = new QVBoxLayout(trackStack);
        vbox->setSpacing(0);
        vbox->setContentsMargins(0, 0, 0, 0);
        _setY(trackStack, timestampBar->height());
        _setWidth(trackStack, _app.trackModel->trackWidth);

        trackCursor = new FrameCursor(this);
        trackCursor->move(40, 0);
        Evt_add(SequencePlaybackEvent::RENDER_FRAME, onRenderFrame)
        Evt_add(TrackModelEvent::MOVE_TRACK, onMoveTrack)

    }

    void onMoveTrack(void *e) {
        if (trackStack->width() < _app.trackModel->trackWidth) {
            _setWidth(trackStack, _app.trackModel->trackWidth);
            qDebug() << this << "trackWidth:" << trackStack->width()<<"x():"<<trackStack->x();
        }

    }

    void add(TrackInfo *trackInfo) {
        Track *track = new Track();
        track->load(trackInfo);
        _setHeight(trackStack, trackStack->height() + track->height());
        vbox->addWidget(track);
        qDebug() << trackStack->height();
    }


    void onRenderFrame(SequencePlaybackEvent *e) {
        int frameIdx = e->frameIdx;
        _setX(trackCursor, frameIdx * App()._().trackModel->frameWidth);
    }

protected:
    virtual void resizeEvent(QResizeEvent *qResizeEvent) override {
        _setHeight(trackCursor, height());
        _setWidth(timestampBar, width());
//        _setWidth(trackStack, width());
        qDebug() << this << "timestampBar:" << timestampBar->width();
    }


    TimestampBar *timestampBar;
    FrameCursor *trackCursor;
    QVBoxLayout *vbox;
};


#endif //SEQTRUAN_TRACKAREA_H
