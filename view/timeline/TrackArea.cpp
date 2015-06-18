//
// Created by manoyuria on 2015/6/18.
//

#include "TrackArea.h"

TrackArea::TrackArea(QWidget *parent) : QWidget(parent) {
    timestampBar = new TimestampBar(this);
    timestampBar->resize(1280, 25);

    trackCursor = new TrackCursor(this);
    trackCursor->move(40, 0);

    trackStack = new QWidget(this);
    QVBoxLayout *vbox = new QVBoxLayout(trackStack);
    vbox->setSpacing(0);
    trackStack->move(0, timestampBar->height());
    trackStack->resize(1280, 10);
}

void TrackArea::add(TrackInfo *trackInfo) {

}
