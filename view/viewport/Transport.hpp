#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_TRANSPORT_H
#define SEQTRUAN_TRANSPORT_H

#include <model/App.hpp>
#include "view/UI.hpp"

class Transport : public QWidget {
public:
    Transport(QWidget *parent) : QWidget(parent) {
        QHBoxLayout *hbox = new QHBoxLayout(this);
        hbox->setSpacing(0);

        QComboBox *frameRate = new QComboBox();
        frameRate->addItems({"24", "30", "60"});
        hbox->addWidget(frameRate);
        connect(frameRate, QComboBox::currentTextChanged, this, onFrameRateChanged);
//
        playButton = new QPushButton();
        playButton->setText("play");
//    Evt_add(ActionEvent_TOGGLE_PLAY,togglePlay);
        connect(playButton, QPushButton::clicked, this, togglePlay);
        hbox->addWidget(playButton);

        QPushButton *stopButton = new QPushButton();
        stopButton->setText("stop");
        hbox->addWidget(stopButton);

        Evt_add(SequencePlaybackEvent::STATE, onState);
    }

private:
    QPushButton *playButton;

    void onState(SequencePlaybackEvent *e) {
        if (e->state == PlaybackEvent::PLAY) {
            playButton->setText("pause");
        }
        else if (PlaybackEvent::PAUSE) {
            playButton->setText("play");
        }
    }

    void togglePlay() {
        App()._().trackModel->sequencePlayback->togglePlay();
//        Evt_dis(ActionEvent::TOGGLE_PLAY, nullptr)

    };

    void onFrameRateChanged() { };
};


#endif //SEQTRUAN_TRANSPORT_H
