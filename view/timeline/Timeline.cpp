//
// Created by toramisu on 2015/6/16.
//

#include <model/App.h>


Timeline::Timeline(QWidget *parent) : QWidget(parent) {
    trackToolBar = new TrackToolBar(this);

    trackPanelArea = new TrackPanelArea(this);
    trackPanelArea->resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, TIMELINE_HEIGHT);
    _setY(trackPanelArea, trackToolBar->height());

    trackArea = new TrackArea(this);
    trackArea->resize(1280, TIMELINE_HEIGHT);
    trackArea->move(TIMELINE_TRACK_PANEL_DEF_WIDTH, 0);
    Evt_add(TrackModelEvent_NEW_TRACK, onNewTrack);

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

    _setQss(vScrollBar, QSS_SCROLLBAR);
    _setQss(hScrollBar, QSS_SCROLLBAR);

    timelineToolBar = new TimelineToolBar(this);
}

void Timeline::onNewTrack() {
    TrackInfo *newTrackInfo = App()._().trackModel->newTrackInfo;
    trackArea->add(newTrackInfo);
    trackPanelArea->add(newTrackInfo);
}

void Timeline::onVScrollBar() {
    int dy = lastVScrollValue - vScrollBar->value();
    lastVScrollValue = vScrollBar->value();
    trackPanelArea->scroll(0, dy);
    trackArea->trackStack->scroll(0, dy);
}

void Timeline::onHScrollBar() {
//    int dx = lastHScrollValue -
    //todo
}

void Timeline::resizeEvent(QResizeEvent *event) {
    _setHeight(trackPanelArea, height());
    _setHeight(trackArea, height() - 15);
    _setHeight(vScrollBar, height() - 85);
    hScrollBar->move(vScrollBar->x() + vScrollBar->width(), vScrollBar->y() + vScrollBar->height());
    _setY(timelineToolBar, hScrollBar->y());
}
