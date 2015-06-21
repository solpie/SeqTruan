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
class TrackArea :public QWidget{
//Q_OBJECT
public:
    TrackArea(QWidget *parent) : QWidget(parent) {
        timestampBar = new TimestampBar(this);
        timestampBar->resize(1280, 25);


        trackStack = new QWidget(this);
        //todo make local
//    QVBoxLayout *vbox = new QVBoxLayout(trackStack);
        vbox = new QVBoxLayout(trackStack);
        vbox->setSpacing(0);
        trackStack->move(0, timestampBar->height());
        trackStack->resize(1280, 10);

        trackCursor = new TrackCursor(this);
        trackCursor->move(40, 0);
    }
    void add(TrackInfo *trackInfo){
        Track *track = new Track();
        track->load(trackInfo->idx);
        _setHeight(trackStack, trackStack->height() + track->height());
        qDebug()<<trackStack->height();
        vbox->addWidget(track);
    }
    QWidget *trackStack;

private:
    TimestampBar *timestampBar;
    TrackCursor *trackCursor;
    QVBoxLayout *vbox;
};


#endif //SEQTRUAN_TRACKAREA_H
