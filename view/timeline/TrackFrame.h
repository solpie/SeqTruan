#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_TRACKFRAME_H
#define SEQTRUAN_TRACKFRAME_H

#include <model/TrackModel.h>
#include "view/UI.h"

class TrackFrame : public QWidget {
public:
    TrackFrame(QWidget *parent);

    void setPixmap(QImage *qImage);

    int idx = 0;
    int holdFrameCount = 0;
    bool isPressLeftButton = false;
    bool isPressRightButton = false;
    int changeWidth = 0;
    int trackInfoIdx;
    int trackFrameInfoIdx;

    void setIdx(int trackFrameIdx);
    void setHoldFrameCount(int holdFrameCount, int dx);

protected:
    void pressAndMoveEvent();

    OverWidget<QWidget> *thumb;

    void paintThumb();

    QPixmap *thumbPixmap;
    QLabel *frameIdx;
    OverWidget<QPushButton> *leftButton;
    OverWidget<QPushButton> *rightButton;


//    QPushButton *leftButton;

};


#endif //SEQTRUAN_TRACKFRAME_H
