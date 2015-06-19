#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_TRACKFRAMETHUMB_H
#define SEQTRUAN_TRACKFRAMETHUMB_H

#include "view/UI.h"
class TrackFrameThumb: public QWidget {
public:
    TrackFrameThumb(QWidget *parent);


protected:
    virtual void paintEvent(QPaintEvent *qPaintEvent) override;
};


#endif //SEQTRUAN_TRACKFRAMETHUMB_H
