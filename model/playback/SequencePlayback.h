#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_SEQQUENCEPLAYBACK_H
#define SEQTRUAN_SEQQUENCEPLAYBACK_H


#include <c++/bits/stringfwd.h>
#include "QTimer"
#include "events/Event.h"

class SequencePlayback {
public:
    SequencePlayback();
    int frameRate;
    int frameIdx;
    std::string state;
    int endFrameIdx;
    void setFramerate(int frameRate);
    void update();
    void play();
    void pause();
    void stop();
private:
    QTimer *timer;

};


#endif //SEQTRUAN_SEQQUENCEPLAYBACK_H
