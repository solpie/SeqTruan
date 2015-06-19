//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_TIMELINE_H
#define SEQTRUAN_TIMELINE_H

#endif //SEQTRUAN_TIMELINE_H

#include <model/TrackModel.h>
#include "TrackToolBar.h"
#include "TrackPanelArea.h"
#include "TrackArea.h"
#include "view/UI.h"
#include "TimelineToolBar.h"
class Timeline : public QWidget {
Q_OBJECT
public:
    Timeline(QWidget *parent = 0);

private:
    void onNewTrack();

    QScrollBar *vScrollBar;
    int lastVScrollValue;
    void onVScrollBar();
    QScrollBar *hScrollBar;
    int lastHScrollValue;

    void onHScrollBar();


protected:
    virtual void resizeEvent(QResizeEvent *qResizeEvent) override;

    TrackToolBar *trackToolBar;
    TrackPanelArea *trackPanelArea;
    TrackArea *trackArea;
    TimelineToolBar *timelineToolBar;
};