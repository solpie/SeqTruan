//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_SEQTRUANWIN_H
#define SEQTRUAN_SEQTRUANWIN_H

#endif //SEQTRUAN_SEQTRUANWIN_H
#include "view/viewport/ViewPort.hpp"
#include "view/UI.hpp"
#include "view/timeline/Timeline.hpp"
class SeqTruanWin : public QWidget {
//Q_OBJECT
public:
    SeqTruanWin(QWidget *parent = 0){
        resize(1440, 1056);

        QSplitter *vSplitter = new QSplitter(Qt::Vertical, this);
        vSplitter->resize(width(), height());
        vSplitter->setOpaqueResize(false);
        ViewPort *viewPort = new ViewPort(vSplitter);
        _timeline = new Timeline(vSplitter);

        setStyleSheet("background:#484848");
        qDebug() << "inited SeqTruanWin";
    }

    virtual ~SeqTruanWin() { }

private:
    ViewPort *_viewport;
    Timeline *_timeline;
    QPushButton *testBtn;
};
