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

    void load(int trackInfoIdx);
    int trackInfoIdx=0;
//    TrackInfo *trackInfo;
    void paintHead();
    OverWidget<QWidget> *headButton;
    void paintTail();

    OverWidget<QWidget> *tailButton;
private:
    vector<TrackFrame*> *trackFrames;
    QWidget *trackFrameArea;
};


#endif //SEQTRUAN_TRACK_H
