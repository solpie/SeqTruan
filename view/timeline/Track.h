#pragma once
//
// Created by manoyuria on 2015/6/18.
//

#ifndef SEQTRUAN_TRACK_H
#define SEQTRUAN_TRACK_H

#include "view/UI.h"
#include "model/TrackModel.h"
#include "TrackFrame.h"
class Track : public QWidget {
public:
    Track();
    Track(QWidget *parent);

    void load(TrackInfo *trackInfo);
    TrackInfo *trackInfo;
    void paintHead();
    OverWidget *headButton;

    void paintTail();

    OverWidget *tailButton;
private:
    QWidget *trackFrameArea;
};


#endif //SEQTRUAN_TRACK_H
