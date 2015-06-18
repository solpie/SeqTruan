#pragma once
//
// Created by manoyuria on 2015/6/18.
//

#ifndef SEQTRUAN_TIMESTAMPBAR_H
#define SEQTRUAN_TIMESTAMPBAR_H

#include "view/UI.h"

class TimestampBar :public QWidget{
public:
    TimestampBar(QWidget *parent);


protected:
    virtual void paintEvent(QPaintEvent *qPaintEvent) override;
};


#endif //SEQTRUAN_TIMESTAMPBAR_H
