//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_TIMELINE_H
#define SEQTRUAN_TIMELINE_H

#endif //SEQTRUAN_TIMELINE_H

#include <model/TrackModel.hpp>
#include "model/App.hpp"
#include "view/timeline/trackPanel/TrackPanelArea.hpp"
#include "view/timeline/trackPanel/TrackToolBar.hpp"
#include "TrackArea.hpp"
#include "view/UI.hpp"
#include "TimelineToolBar.hpp"

class Timeline : public QWidget {
public:
    Timeline(QWidget *parent = 0) : QWidget(parent) {
        trackToolBar = new TrackToolBar(this);


        trackArea = new TrackArea(this);
        trackArea->resize(1280, TIMELINE_HEIGHT);
        trackArea->move(TIMELINE_TRACK_PANEL_DEF_WIDTH, 0);

        trackPanelArea = new TrackPanelArea(this);
        trackPanelArea->resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, TIMELINE_HEIGHT);
        UI::setY(trackPanelArea, trackToolBar->height());

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
        UI::setHeight(this, TIMELINE_HEIGHT);

        UI::setQss(vScrollBar, QSS_SCROLLBAR);
        UI::setQss(hScrollBar, QSS_SCROLLBAR);


        timelineToolBar = new TimelineToolBar(this);

        Evt_add(TrackModelEvent::NEW_TRACK, onNewTrack);
        Evt_add(TrackModelEvent::LOAD_COMPLETE, onLoadTrackImage);
        Evt_add(TrackModelEvent::MOVE_TRACK, onMoveTrack)

    }

    void onMoveTrack(void *e) {
        int trackWidth = _app.trackModel->trackWidth;
        if (trackArea->trackStack->width() < trackWidth) {
            UI::setWidth(trackArea->trackStack, trackWidth);
            hScrollBar->setRange(0, trackWidth - hScrollBar->width());
            qDebug() << this << "resize trackStack " << "trackWidth:" << trackArea->trackStack->width();
        }
        if (trackWidth > trackArea->timestampBar->width()) {
            UI::setWidth(trackArea->timestampBar, trackWidth);
        }
    }

private:
    void onLoadTrackImage(int idx = 0) {
        trackArea->update();
    }

    void onNewTrack(TrackInfo *newTrackInfo) {
        trackArea->add(newTrackInfo);
        trackPanelArea->add(newTrackInfo);
        _app.trackModel->sequencePlayback->update();
    }

    QScrollBar *vScrollBar;
    int lastVScrollValue;

    void onVScrollBar() {
        int dy = lastVScrollValue - vScrollBar->value();
        lastVScrollValue = vScrollBar->value();
        trackPanelArea->scroll(0, dy);
        trackArea->trackStack->scroll(0, dy);
    }

    QScrollBar *hScrollBar;
    int lastHScrollValue;

    void onHScrollBar() {
        int dx = lastHScrollValue - hScrollBar->value();
        lastHScrollValue = hScrollBar->value();
        trackArea->scroll(dx, 0);
        Evt_dis(ActionEvent::SCROLL_TIMELINE_HBAR, &lastHScrollValue);
    }


protected:
    virtual void resizeEvent(QResizeEvent *qResizeEvent) override {
        trackArea->resize(width(), height() - 15);
        hScrollBar->setRange(0, trackArea->trackStack->width() - hScrollBar->width());
//        _setHeight(trackArea, height() - 15);
        UI::setHeight(vScrollBar, height() - 40);
        hScrollBar->move(vScrollBar->x() + vScrollBar->width(), vScrollBar->y() + vScrollBar->height());
        UI::setWidth(hScrollBar, width() - TIMELINE_TRACK_PANEL_DEF_WIDTH);
        UI::setY(timelineToolBar, hScrollBar->y());
    }

    TrackToolBar *trackToolBar;
    TrackPanelArea *trackPanelArea;
    TrackArea *trackArea;
    TimelineToolBar *timelineToolBar;
};