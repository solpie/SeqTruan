#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_AUDIOPLAYBACK_H
#define SEQTRUAN_AUDIOPLAYBACK_H

#include "QtMultimedia"
//#include "QtMultimediaWidgets"
#include "QtCore"
#include "QMediaContent"
#include "events/Event.hpp"

class AudioPlayback {
public:
    AudioPlayback() {
        audioplayback = new QMediaPlayer();
        audioplayback->setVolume(50);
        audioplayback->connect(audioplayback, QMediaPlayer::positionChanged, [this]{this->onPosition();});
    }

    void load(QString path) {
        audioplayback->setMedia(QMediaContent(QUrl(path)));
    }

    void seek(int position) {
        audioplayback->setPosition(position);
    }

    void play(){
        if (audioplayback->state() != QMediaPlayer::PlayingState) {
            audioplayback->play();
        }
    }

    void pause() {
        if (audioplayback->state() == QMediaPlayer::PlayingState) {
            audioplayback->pause();
        }
    }

    void stop(){

    }

    void setVolume(int vol){
        audioplayback->setVolume(vol);
    }

private:
    QMediaPlayer *audioplayback;

    void onPosition(){
//    qDebug() << audioplayback->position() << audioplayback->state();
//    Evt_dis(AUDIO_TICK);
    }
};


#endif //SEQTRUAN_AUDIOPLAYBACK_H
