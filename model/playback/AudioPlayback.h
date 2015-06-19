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

class AudioPlayback {
public:
    AudioPlayback();

    void load(QString path);

    void seek(int position);

    void play();

    void pause();

    void stop();

    void setVolume(int vol);

private:
    QMediaPlayer *audioplayback;

    void onPosition();
};


#endif //SEQTRUAN_AUDIOPLAYBACK_H
