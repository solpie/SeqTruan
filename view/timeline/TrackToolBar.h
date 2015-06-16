//
// Created by toramisu on 2015/6/16.
//
#pragma once

#include <QWidget>
#include <QPushButton>

#ifndef SEQTRUAN_TRACKTOOLBAR_H
#define SEQTRUAN_TRACKTOOLBAR_H

#endif //SEQTRUAN_TRACKTOOLBAR_H
class TrackToolBar:public QWidget{
    Q_OBJECT
public:
    TrackToolBar(QWidget *parent=0);
    void onClkNewTrackBtn();
private:
    QPushButton *newTrackButton;



};