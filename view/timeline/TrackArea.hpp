#pragma once
//
// Created by manoyuria on 2015/6/18.
//

#ifndef SEQTRUAN_TRACKAREA_H
#define SEQTRUAN_TRACKAREA_H

#include <model/TrackModel.hpp>
#include "view/UI.hpp"
#include "TrackCursor.hpp"
#include "TimestampBar.hpp"
#include "Track.hpp"

class TrackArea : public QWidget {
public:
    TrackArea(QWidget *parent) : QWidget(parent) {
        timestampBar = new TimestampBar(this);
        timestampBar->resize(1280, 25);


        trackStack = new QWidget(this);
        //todo make local
//    QVBoxLayout *vbox = new QVBoxLayout(trackStack);
        vbox = new QVBoxLayout(trackStack);
        vbox->setSpacing(0);
        vbox->setContentsMargins(0, 0, 0, 0);
        _setY(trackStack,timestampBar->height());
        trackStack->resize(1280, 10);

        trackCursor = new TrackCursor(this);
        trackCursor->move(40, 0);
        Evt_add(SequencePlaybackEvent::RENDER_FRAME, onRenderFrame)
    }

    void add(TrackInfo *trackInfo) {
        Track *track = new Track();
        track->load(trackInfo);
        _setHeight(trackStack, trackStack->height() + track->height());
        vbox->addWidget(track);
        qDebug() << trackStack->height();
    }

    QWidget *trackStack;

    void onRenderFrame(SequencePlaybackEvent *e) {
        int frameIdx = e->frameIdx;
        _setX(trackCursor,frameIdx*App()._().trackModel->frameWidth);
    }

protected:
    virtual void resizeEvent(QResizeEvent *qResizeEvent) override {
        _setHeight(trackCursor, height());
    }


    TimestampBar *timestampBar;
    TrackCursor *trackCursor;
    QVBoxLayout *vbox;
};


#endif //SEQTRUAN_TRACKAREA_H
