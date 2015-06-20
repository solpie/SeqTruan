#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_SEQQUENCEPLAYBACK_H
#define SEQTRUAN_SEQQUENCEPLAYBACK_H


#include <c++/bits/stringfwd.h>
#include "QTimer"
#include "events/Event.hpp"

class SequencePlayback {
public:
    SequencePlayback() {
        frameRate = 24;
        frameIdx = 1;
        state = "stop";
        timer = new QTimer();
    }
    int frameRate;
    int frameIdx;
    std::string state;
    int endFrameIdx;
    void setFramerate(int frameRate){
        this->frameRate = frameRate;
        this->timer->setInterval(1000 / this->frameRate);
    }
    void update(){
        frameIdx = (frameIdx + 1) % endFrameIdx;
    }
    void play(){
        if (!timer->isActive()) {
            timer->start();
        }
    }
    void pause(){
        if (timer->isActive()) {
            timer->stop();
        }
    }
    void stop(){
        if (timer->isActive()) {
            timer->stop();
        }
        frameIdx = 1;
    }
private:
    QTimer *timer;

};


#endif //SEQTRUAN_SEQQUENCEPLAYBACK_H
