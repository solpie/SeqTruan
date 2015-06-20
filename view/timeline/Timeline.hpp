//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_TIMELINE_H
#define SEQTRUAN_TIMELINE_H

#endif //SEQTRUAN_TIMELINE_H

#include <model/TrackModel.hpp>
#include "model/App.hpp"
#include "trackPanel/TrackPanelArea.hpp"
#include "trackPanel/TrackToolBar.hpp"
#include "TrackArea.hpp"
#include "view/UI.hpp"
#include "TimelineToolBar.hpp"
class Timeline : public QWidget {
Q_OBJECT
public:
    Timeline(QWidget *parent = 0): QWidget(parent) {
        trackToolBar = new TrackToolBar(this);

        trackPanelArea = new TrackPanelArea(this);
        trackPanelArea->resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, TIMELINE_HEIGHT);
        _setY(trackPanelArea, trackToolBar->height());

        trackArea = new TrackArea(this);
        trackArea->resize(1280, TIMELINE_HEIGHT);
        trackArea->move(TIMELINE_TRACK_PANEL_DEF_WIDTH, 0);
//    Evt_add(TrackModelEvent_NEW_TRACK, onNewTrack);
        Evt()._().add(TrackModelEvent_NEW_TRACK, [this] (){ onNewTrack(); });
//    Evt::_().add(TrackModelEvent_NEW_TRACK, onNewTrack);

//    Evt::_().add(TrackModelEvent_NEW_TRACK, std::bind(this, &Timeline::onNewTrack));
//    Evt::_().add(TrackModelEvent_NEW_TRACK,  onNewTrack);
//    TrackInfo *trackInfo = new TrackInfo("hh");
//    onNewTrack(trackInfo);

        vScrollBar = new QScrollBar(this);
        lastVScrollValue = 0;
        vScrollBar->setPageStep(100);
        vScrollBar->move(TIMELINE_TRACK_PANEL_DEF_WIDTH - 15, trackToolBar->height());
        vScrollBar->resize(15, 235);
        connect(vScrollBar, QScrollBar::valueChanged, this, onVScrollBar);

        hScrollBar = new QScrollBar(Qt::Horizontal, this);
        lastHScrollValue = 0;
        hScrollBar->resize(500, 15);
        hScrollBar->setPageStep(200);
        connect(hScrollBar, QScrollBar::valueChanged, this, onHScrollBar);
        _setHeight(this, TIMELINE_HEIGHT);

        UI::setQss(vScrollBar, QSS_SCROLLBAR);
        UI::setQss(hScrollBar, QSS_SCROLLBAR);

        timelineToolBar = new TimelineToolBar(this);
    }

private:
    void onNewTrack(){
        TrackInfo *newTrackInfo = App()._().trackModel->newTrackInfo;
        trackArea->add(newTrackInfo);
        trackPanelArea->add(newTrackInfo);
    }

    QScrollBar *vScrollBar;
    int lastVScrollValue;
    void onVScrollBar(){
        int dy = lastVScrollValue - vScrollBar->value();
        lastVScrollValue = vScrollBar->value();
        trackPanelArea->scroll(0, dy);
        trackArea->trackStack->scroll(0, dy);
    }
    QScrollBar *hScrollBar;
    int lastHScrollValue;

    void onHScrollBar(){
//    int dx = lastHScrollValue -
        //todo
    }


protected:
    virtual void resizeEvent(QResizeEvent *qResizeEvent) override {
        _setHeight(trackPanelArea, height());
        _setHeight(trackArea, height() - 15);
        _setHeight(vScrollBar, height() - 85);
        hScrollBar->move(vScrollBar->x() + vScrollBar->width(), vScrollBar->y() + vScrollBar->height());
        _setY(timelineToolBar, hScrollBar->y());
    }

    TrackToolBar *trackToolBar;
    TrackPanelArea *trackPanelArea;
    TrackArea *trackArea;
    TimelineToolBar *timelineToolBar;
};