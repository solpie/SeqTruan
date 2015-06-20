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
#include <view/timeline/TrackFrame.h>
#include <view/timeline/Track.h>
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
    int idx;
    int holdCount;
    int startIdx;
//    int idx;

    QImage *payLoad;
    int startFrameIdx=0;

    TrackFrame *trackFrame;
    int trackInfoIdx;
//    auto *payLoad;
//    PayLoad payLoad;
};

class TrackInfo {
public:
    TrackInfo(QString name) {
        this->name = name;
        trackFrameInfos = new vector<TrackFrameInfo *>();
    };
    QString name;
    vector<TrackFrameInfo *> *trackFrameInfos;
    int startIdx;
    int idx;
    int getCurTrackFrameIdx() {
        return _trackFrameIdx;
    };
//    Track *track;
//    void updateTrackInfo(TrackInfo *trackInfo,int... p);
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

    void relayout(int trackInfoIdx,int trackFrameInfoIdx);
    TrackInfo *getTrackInfo(int tIdx){ return _trackInfos->at(tIdx);}
    TrackFrameInfo *getTrackFrameInfo(int tIdx,int tfIdx){ return getTrackInfo(tIdx)->trackFrameInfos->at(tfIdx);}
    int frameWidth = 40;
    SequencePlayback *sequencePlayback;
    AudioPlayback *audioPlayback;
private:
    vector<TrackInfo *> *_trackInfos;

};