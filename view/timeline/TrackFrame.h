#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_TRACKFRAME_H
#define SEQTRUAN_TRACKFRAME_H

#include "view/UI.h"

class TrackFrame : public QWidget {
public:
    TrackFrame(QWidget *parent);

    void setPixmap(QImage *qImage);
    int idx=0;

private:
    OverWidget<QWidget> *thumb;

    void paintThumb();

    QPixmap *thumbPixmap;
//    int thumbWidth;
//    int thumbHeight;
    QLabel *frameIdx;
    OverWidget<QPushButton> *leftButton;
    OverWidget<QPushButton> *rightButton;
//    QPushButton *leftButton;
};


#endif //SEQTRUAN_TRACKFRAME_H
