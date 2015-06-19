//
// Created by manoyuria on 2015/6/19.
//

#include "AudioPlayback.h"
#include "events/Event.h"

AudioPlayback::AudioPlayback() {
    audioplayback = new QMediaPlayer();
    audioplayback->setVolume(50);
    audioplayback->connect(audioplayback, QMediaPlayer::positionChanged, [this]{this->onPosition();});
}

void AudioPlayback::onPosition() {
//    qDebug() << audioplayback->position() << audioplayback->state();
    Evt_dis(AUDIO_TICK);
}

void AudioPlayback::load(QString path) {
    audioplayback->setMedia(QMediaContent(QUrl(path)));
}

void AudioPlayback::seek(int position) {
    audioplayback->setPosition(position);
}

void AudioPlayback::play() {
    if (audioplayback->state() != QMediaPlayer::PlayingState) {
        audioplayback->play();
    }
}

void AudioPlayback::pause() {
    if (audioplayback->state() == QMediaPlayer::PlayingState) {
        audioplayback->pause();
    }
}

void AudioPlayback::setVolume(int vol) {
    audioplayback->setVolume(vol);
}

void AudioPlayback::stop() {

}
