//
// Created by manoyuria on 2015/6/18.
//

#include "TrackArea.h"
TrackArea::TrackArea(QWidget *parent) : QWidget(parent) {
    trackCursor = new TrackCursor(this);
    trackCursor->move(40, 0);
}
