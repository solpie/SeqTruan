#pragma once
//
// Created by manoyuria on 2015/6/20.
//

#ifndef SEQTRUAN_TRACKPANEL_H
#define SEQTRUAN_TRACKPANEL_H

#include "view/UI.h"
class TrackPanel :public QWidget{
public:
    TrackPanel(QWidget *parent=0);
    void setTrackName(QString name);

private:
    QLabel *trackNameLabel;
    QCheckBox *visibleCheck;
    void onOpacityChanged(int newPos);
    void onPressSlider();
    QSlider *opacitySlider;

};


#endif //SEQTRUAN_TRACKPANEL_H
