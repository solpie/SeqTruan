//
// Created by manoyuria on 2015/6/18.
//
#pragma once

#ifndef SEQTRUAN_TRACKPANELAREA_H
#define SEQTRUAN_TRACKPANELAREA_H

#include <model/TrackModel.hpp>
#include "view/UI.hpp"
#include "view/timeline/trackPanel/TrackPanel.hpp"

class TrackPanelArea : public QWidget {
public:
    TrackPanelArea(QWidget *parent = 0) : QWidget(parent) {
        QWidget *stack = new QWidget(this);
        stack->resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, 10);
        vbox = new QVBoxLayout(stack);
        vbox->setSpacing(0);
        vbox->setContentsMargins(0, 0, 0, 0);
    }

    void add(TrackInfo *trackInfo) {
        TrackPanel *tp = new TrackPanel();
        tp->setTrackName(trackInfo->name);
        _setHeight(vbox->parentWidget(), vbox->parentWidget()->height() + tp->height());
        vbox->addWidget(tp);
        qDebug() << this << this->height();
    }


    QVBoxLayout *vbox;
};

#endif //SEQTRUAN_TRACKPANELAREA_H


