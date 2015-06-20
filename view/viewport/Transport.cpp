//
// Created by manoyuria on 2015/6/19.
//

#include "Transport.h"
Transport::Transport(QWidget *parent) : QWidget(parent) {
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
void Transport::onFrameRateChanged()
{

}

void Transport::togglePlay() {

}
