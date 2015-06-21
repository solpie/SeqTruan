#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_SEQQUENCEPLAYBACK_H
#define SEQTRUAN_SEQQUENCEPLAYBACK_H


#include "QTimer"
#include "events/Event.hpp"

class SequencePlayback {
public:
    SequencePlayback() {
        frameRate = 24;
        frameIdx = 1;
        state = PlaybackEvent::STOP;
//        state = new string("stop");
        timer = new QTimer();
        setFramerate(24);
    }

    int frameRate;
    int frameIdx;
    std::string state;
    int endFrameIdx;

    void setFramerate(int frameRate) {
        this->frameRate = frameRate;
        this->timer->setInterval(1000 / this->frameRate);
//        timer->connect(timer, QTimer::timeout, update);
    }

    void update() {
        frameIdx = (frameIdx + 1) % endFrameIdx;
        SequencePlaybackEvent *e = new SequencePlaybackEvent();
        e->frameIdx = frameIdx;
        Evt_dis(SequencePlaybackEvent::RENDER_FRAME, e)

    }

    void togglePlay() {
        if (state == PlaybackEvent::PLAY) {
            setState(PlaybackEvent::PAUSE);
        }
        else if (state == PlaybackEvent::PAUSE || state == PlaybackEvent::STOP) {
            setState(PlaybackEvent::PLAY);
        }
    }

    void setState(string newstate) {
        if (state != newstate) {
            state = newstate;
        }
        SequencePlaybackEvent *e = new SequencePlaybackEvent();
        e->state = state;
        Evt_dis(SequencePlaybackEvent::STATE, e);
    }

    void play() {
        if (!timer->isActive()) {
            timer->start();
        }
    }

    void pause() {
        if (timer->isActive()) {
            timer->stop();
        }
    }

    void stop() {
        if (timer->isActive()) {
            timer->stop();
        }
        frameIdx = 1;
    }

private:
    QTimer *timer;

};


#endif //SEQTRUAN_SEQQUENCEPLAYBACK_H
