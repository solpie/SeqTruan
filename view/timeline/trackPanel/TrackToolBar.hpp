//
// Created by toramisu on 2015/6/16.
//
#pragma once

#include "view/UI.hpp"
//#include <model/App.h>

#ifndef SEQTRUAN_TRACKTOOLBAR_H
#define SEQTRUAN_TRACKTOOLBAR_H

#endif //SEQTRUAN_TRACKTOOLBAR_H
class TrackToolBar:public QWidget{
public:
    TrackToolBar(QWidget *parent=0):QWidget(parent)
    {
        resize(250, 25);
        newTrackButton = new QPushButton("new Track",this);
//    QObject::connect(newTrackButton, &QPushButton::clicked, someFunction);
//    newTrackButton->mouseMoveEvent
//    TrackModel *t = TrackModel::_();
//    t->newTrack();
//        connect(newTrackButton, &QPushButton::clicked, []{
////        printf("click me");
//            App()._().trackModel->newTrack("new track","");
//        });
//    this.pressed.connect(someFunction);
//    this->onClkNewTrackBtn();
    }
    void onClkNewTrackBtn(){};

    void onVScrollBar(){};

private:
    QPushButton *newTrackButton;



};