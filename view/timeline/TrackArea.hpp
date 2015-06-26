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
#include "events/ActionEvent.hpp"

class TrackArea : public QWidget {
public:
    QWidget *trackStack;

    TrackArea(QWidget *parent) : QWidget(parent) {
        int trackWidth = _app.trackModel->trackWidth;
        timestampBar = new TimestampBar(this);
        timestampBar->resize(trackWidth, 25);


        trackStack = new QWidget(this);
        trackStack->setObjectName("track");
        trackStack->setStyleSheet("QWidget#track{background:#343434;}");
        //todo make local
//    QVBoxLayout *vbox = new QVBoxLayout(trackStack);
        vbox = new QVBoxLayout(trackStack);
        vbox->setSpacing(0);
        vbox->setContentsMargins(0, 0, 0, 0);
        UI::setY(trackStack, timestampBar->height());
        UI::setWidth(trackStack, trackWidth);

        trackCursor = new FrameCursor(this);
        trackCursor->setPosXbyIdx(1);

        Evt_add(SequencePlaybackEvent::RENDER_FRAME, onRenderFrame);
    }


    void add(TrackInfo *trackInfo) {
        Track *track = new Track();
        track->load(trackInfo);
        UI::setHeight(trackStack, trackStack->height() + track->height());
        qDebug() << this << "track Width:" << track->width();
        vbox->addWidget(track);
        qDebug() << this << "track Width:" << track->width() << "trackStack height:" << trackStack->height();
    }


    void onRenderFrame(SequencePlaybackEvent *e) {
        int frameIdx = e->frameIdx;
//        UI::setX(trackCursor, frameIdx * _app.trackModel->frameWidth);
        trackCursor->setPosXbyIdx(frameIdx);
    }

    TimestampBar *timestampBar;

protected:

    virtual void resizeEvent(QResizeEvent *qResizeEvent) override {
        UI::setHeight(trackCursor, height());
        UI::setWidth(timestampBar, width());
//        _setWidth(trackStack, width());
        qDebug() << this << "timestampBar:" << timestampBar->width();
    }


    FrameCursor *trackCursor;
    QVBoxLayout *vbox;
};


#endif //SEQTRUAN_TRACKAREA_H
