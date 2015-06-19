//
// Created by manoyuria on 2015/6/19.
//

#include "SequencePlayback.h"

SequencePlayback::SequencePlayback() {
    frameRate = 24;
    frameIdx = 1;
    state = "stop";
    timer = new QTimer();
}

void SequencePlayback::setFramerate(int frameRate) {
    this->frameRate = frameRate;
    this->timer->setInterval(1000 / this->frameRate);
}

void SequencePlayback::play() {
    if (!timer->isActive()) {
        timer->start();
    }
}

void SequencePlayback::pause() {
    if (timer->isActive()) {
        timer->stop();
    }
}

void SequencePlayback::stop() {
    if (timer->isActive()) {
        timer->stop();
    }
    frameIdx = 1;
}

void SequencePlayback::update() {
    frameIdx = (frameIdx + 1) % endFrameIdx;
}
