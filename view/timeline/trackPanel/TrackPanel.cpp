//
// Created by manoyuria on 2015/6/20.
//

#include "TrackPanel.h"


TrackPanel::TrackPanel(QWidget *parent):QWidget(parent) {
    resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, TIMELINE_TRACK_DEF_HEIGHT);
    trackNameLabel = new QLabel(this);
    trackNameLabel->move(5, 5);
}

void TrackPanel::setTrackName(QString tname) {
    trackNameLabel->setText(tname);
}
