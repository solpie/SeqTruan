#pragma once
//
// Created by manoyuria on 2015/6/18.
//

#ifndef SEQTRUAN_TRACKAREA_H
#define SEQTRUAN_TRACKAREA_H

#include <model/TrackModel.h>
#include "view/UI.h"
#include "TrackCursor.h"
#include "TimestampBar.h"
class TrackArea :public QWidget{
Q_OBJECT
public:
    TrackArea(QWidget *parent);
    void add(TrackInfo *trackInfo);
    QWidget *trackStack;

private:
    TimestampBar *timestampBar;
    TrackCursor *trackCursor;
    QVBoxLayout *vbox;
};


#endif //SEQTRUAN_TRACKAREA_H
