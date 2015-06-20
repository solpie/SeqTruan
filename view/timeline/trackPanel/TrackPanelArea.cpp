//
// Created by manoyuria on 2015/6/18.
//
#include "TrackPanelArea.h"
#include "TrackPanel.h"

TrackPanelArea::TrackPanelArea(QWidget *parent) : QWidget(parent) {
    QWidget *stack = new QWidget(this);
    stack->resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, 10);
    vbox = new QVBoxLayout(stack);
    vbox->setSpacing(0);
    vbox->setContentsMargins(0, 0, 0, 0);
}

void TrackPanelArea::add(TrackInfo *trackInfo) {
    TrackPanel *tp = new TrackPanel();
    tp->setTrackName(trackInfo->name);
    _setHeight(vbox->parentWidget(), vbox->parentWidget()->height() + tp->height());
    vbox->addWidget(tp);
    qDebug() << this << this->height();
//    tp = TrackPanel()
//    tp.setTrackName(trackInfo.name)
//    self.trackPanelStack.resize(self.trackPanelStack.width(), self.trackPanelStack.height() + tp.height())
//    self.vbox.addWidget(tp)
//    self.trackPanels.append(tp)
//# self.scrollContentsBy(500,10)
//    print(self.height())
}
