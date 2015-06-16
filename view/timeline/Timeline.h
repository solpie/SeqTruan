//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_TIMELINE_H
#define SEQTRUAN_TIMELINE_H

#endif //SEQTRUAN_TIMELINE_H

#include "QWidget"
#include "TrackToolBar.h"

class Timeline:public QWidget{
Q_OBJECT
public:
    Timeline(QWidget *parent=0);

private:
    TrackToolBar *trackToolBar;
};