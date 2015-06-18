#pragma once
//
// Created by manoyuria on 2015/6/18.
//

#ifndef SEQTRUAN_TRACKAREA_H
#define SEQTRUAN_TRACKAREA_H

#include "view/UI.h"
#include "TrackCursor.h"

class TrackArea :public QWidget{
Q_OBJECT
public:
    TrackArea(QWidget *parent);

private:
    TrackCursor *trackCursor;
};


#endif //SEQTRUAN_TRACKAREA_H
