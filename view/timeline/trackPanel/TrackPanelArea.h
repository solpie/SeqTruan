//
// Created by manoyuria on 2015/6/18.
//
#pragma once

#ifndef SEQTRUAN_TRACKPANELAREA_H
#define SEQTRUAN_TRACKPANELAREA_H

#include <model/TrackModel.h>
#include "view/UI.h"

class TrackPanelArea : public QWidget {
Q_OBJECT
public:
    TrackPanelArea(QWidget *parent = 0);

    void add(TrackInfo *trackInfo);


    QVBoxLayout *vbox;
};

#endif //SEQTRUAN_TRACKPANELAREA_H


