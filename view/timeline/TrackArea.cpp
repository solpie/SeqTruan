//
// Created by manoyuria on 2015/6/18.
//

#include "TrackArea.h"
#include "Track.h"

TrackArea::TrackArea(QWidget *parent) : QWidget(parent) {
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

void TrackArea::add(TrackInfo *trackInfo) {
    Track *track = new Track();
    track->load(trackInfo);
    _setHeight(trackStack, trackStack->height() + track->height());
    qDebug()<<trackStack->height();
    vbox->addWidget(track);
}
