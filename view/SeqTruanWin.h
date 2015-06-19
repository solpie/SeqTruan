//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_SEQTRUANWIN_H
#define SEQTRUAN_SEQTRUANWIN_H

#endif //SEQTRUAN_SEQTRUANWIN_H
#include "viewport/ViewPort.h"
#include "QWidget"
#include "QtCore"
#include "timeline/Timeline.h"
class SeqTruanWin : public QWidget {
Q_OBJECT
public:
    SeqTruanWin(QWidget *parent = 0);

    virtual ~SeqTruanWin() { }

private:
    ViewPort *_viewport;
    Timeline *_timeline;
    QPushButton *testBtn;
};
