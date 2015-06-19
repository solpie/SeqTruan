//
// Created by toramisu on 2015/6/16.
//

#include <model/App.h>


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

    vScrollBar = new QScrollBar(this);
    lastVScrollValue = 0;
    vScrollBar->setPageStep(100);
    vScrollBar->move(TIMELINE_TRACK_PANEL_DEF_WIDTH - 15, trackToolBar->height());
    vScrollBar->resize(15, 235);
    connect(vScrollBar, QScrollBar::valueChanged, this, onVScrollBar);

    hScrollBar = new QScrollBar(Qt::Horizontal,this);
    lastHScrollValue = 0;
    hScrollBar->resize(500, 15);
    hScrollBar->setPageStep(200);
    connect(hScrollBar, QScrollBar::valueChanged, this, onHScrollBar);
    setHeight(this, TIMELINE_HEIGHT);

    QFile f(":/qss_scrollbar");
    f.open(QIODevice::ReadOnly);
    QByteArray ba = f.readAll();
    f.close();
    vScrollBar->setStyleSheet(ba.data());
    hScrollBar->setStyleSheet(ba.data());
//    qDebug()<<UI::_().getQss(":/qss_scrollBar");
//    f.close();
//    setQss(vScrollBar, ":/qss_scrollBar");
//    sq(*vScrollBar, ":/qss_scrollBar");
//    UI::setQss(vScrollBar, ":/qss_scrollBar");
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
    setHeight(trackPanelArea, height());
    setHeight(trackArea, height() - 15);
    setHeight(vScrollBar, height() - 85);
    hScrollBar->move(vScrollBar->x() + vScrollBar->width(), vScrollBar->y() + vScrollBar->height());
    setY(timelineToolBar, hScrollBar->y());
}
