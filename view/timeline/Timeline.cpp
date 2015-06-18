//
// Created by toramisu on 2015/6/16.
//

#include "Timeline.h"
#include "view/Theme.h"
#include "view/UI.h"

Timeline::Timeline(QWidget *parent) : QWidget(parent) {
    trackToolBar = new TrackToolBar(this);

    trackPanelArea = new TrackPanelArea(this);
    setY(trackPanelArea, trackToolBar->height());
    trackPanelArea->resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, TIMELINE_HEIGHT);
}
