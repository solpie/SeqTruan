#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_TIMELINTOOLBAR_H
#define SEQTRUAN_TIMELINTOOLBAR_H

#include "view/UI.hpp"
class TimelineToolBar : public QWidget {
public:
    TimelineToolBar(QWidget *parent): QWidget(parent) {
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


};


#endif //SEQTRUAN_TIMELINTOOLBAR_H
