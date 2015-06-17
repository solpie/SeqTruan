//
// Created by toramisu on 2015/6/16.
//

#include "SeqTruanWin.h"
SeqTruanWin::SeqTruanWin(QWidget *parent)
{
    resize(1440, 1056);
    timeline = new Timeline(this);
    timeline->move(0, 720);
    timeline->resize(1440, 720);
    timeline->show();
    qDebug()<<"inited SeqTruanWin";
//    testBtn = new QPushButton();
//    testBtn->resize(100, 30);
}


