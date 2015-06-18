//
// Created by manoyuria on 2015/6/18.
//
#pragma once

#ifndef SEQTRUAN_TRACKPANELAREA_H
#define SEQTRUAN_TRACKPANELAREA_H

#include <model/TrackModel.h>
#include "QWidget"
#include "TrackCursor.h"

class TrackPanelArea : public QWidget {
Q_OBJECT
public:
    TrackPanelArea(QWidget *parent=0);

    void add(TrackInfo *trackInfo);



};

#endif //SEQTRUAN_TRACKPANELAREA_H


