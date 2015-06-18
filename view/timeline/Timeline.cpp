//
// Created by toramisu on 2015/6/16.
//

#include <model/App.h>
#include "Timeline.h"

void func1(TrackInfo *trackInfo) {

}

Timeline::Timeline(QWidget *parent) : QWidget(parent) {
    trackToolBar = new TrackToolBar(this);

    trackPanelArea = new TrackPanelArea(this);
    trackPanelArea->resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, TIMELINE_HEIGHT);
    setY(trackPanelArea, trackToolBar->height());

    trackArea = new TrackArea(this);
    trackArea->resize(1280, TIMELINE_HEIGHT);
    trackArea->move(TIMELINE_TRACK_PANEL_DEF_WIDTH, 0);
//    Evt::_().add(TrackModelEvent::NEW_TRACK,[](TrackInfo *trackInfo){onNewTrack(trackInfo);});
//    Evt::_().add("newTrack",func1);
    Evt_add("newTrack", onNewTrack);
}

void Timeline::onNewTrack() {
    TrackInfo* newTrackInfo = App()._().trackModel->newTrackInfo;
}
