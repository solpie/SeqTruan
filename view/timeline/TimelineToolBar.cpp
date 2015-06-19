//
// Created by manoyuria on 2015/6/19.
//

#include "TimelineToolBar.h"

TimelineToolBar::TimelineToolBar(QWidget *parent) : QWidget(parent) {
    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setSpacing(0);
    hbox->setContentsMargins(0, 0, 0, 0);

    QPushButton *startFrameButton = new QPushButton();
    hbox->addWidget(startFrameButton);
    startFrameButton->setText("startFrame");

    resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, 15);
//    self.startFrameLabel = QLineEdit()
//    self.startFrameLabel.setText('1')
//    hbox.addWidget(self.startFrameLabel)
}
