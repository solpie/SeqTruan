#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_TRANSPORT_H
#define SEQTRUAN_TRANSPORT_H

#include "view/UI.hpp"
class Transport :public QWidget{
public:
    Transport(QWidget *parent): QWidget(parent) {
        QHBoxLayout *hbox = new QHBoxLayout(this);
        hbox->setSpacing(0);

        QComboBox *frameRate = new QComboBox();
        frameRate->addItems({"24", "30", "60"});
        hbox->addWidget(frameRate);
        connect(frameRate, QComboBox::currentTextChanged, this, onFrameRateChanged);
//
        QPushButton *playButton = new QPushButton();
        playButton->setText("play");
//    Evt_add(ActionEvent_TOGGLE_PLAY,togglePlay);
        connect(playButton,QPushButton::clicked,this,togglePlay);
        hbox->addWidget(playButton);

        QPushButton *stopButton = new QPushButton();
        stopButton->setText("stop");
        hbox->addWidget(stopButton);



    }

private:
    void togglePlay(){
        Evt()._().seq->dis("test", new SequencePlaybackEvent());

    };

    void onFrameRateChanged(){};
};


#endif //SEQTRUAN_TRANSPORT_H
