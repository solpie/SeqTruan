//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_TRACKMODEL_H
#define SEQTRUAN_TRACKMODEL_H

#endif //SEQTRUAN_TRACKMODEL_H

#include "Singleton.h"
#include <functional>
#include <vector>
#include <events/Event.h>
#include <QtCore/qstring.h>
#include "playback/SequencePlayback.h"
#include "playback/AudioPlayback.h"
//template<typename P>
//class PayLoad {
//public:
//    P get() {
//        return this;
//    };
//};

class TrackFrameInfo {
public:
    int frameIdx;
    int holdCount;
    int startIdx;
//    int frameIdx;

    QImage *payLoad;
//    auto *payLoad;
//    PayLoad payLoad;
};

class TrackInfo {
public:
    TrackInfo(QString name) {
        this->name = name;
    };
    QString name;
    vector<TrackFrameInfo*> frames;
    int startIdx;

    int getCurTrackFrameIdx() {
        return _trackFrameIdx;
    };
private:
    int _trackFrameIdx;
};

class TrackModel {
public:
    TrackModel();
    void newTrack(QString name, QString imagesPath);

    void func1();

    TrackInfo *newTrackInfo;

    void setZoomLevel(int lv);

    int frameWidth = 40;
    SequencePlayback *sequencePlayback;
    AudioPlayback *audioPlayback;
private:
    vector<TrackInfo *> _trackInfos;

};