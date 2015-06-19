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
//    auto *payLoad;
//    PayLoad payLoad;
};

class TrackInfo {
public:
    TrackInfo(QString name) {
        this->name = name;
    };
    QString name;
    vector<TrackFrameInfo> frames;
    int startIdx;

    int getCurTrackFrameIdx() {
        return _trackFrameIdx;
    };
private:
    int _trackFrameIdx;
};

class TrackModel {
public:

    void newTrack(QString name, QString imagesPath);

    void func1();
    TrackInfo *newTrackInfo;

    void setZoomLevel(int lv);


private:
    vector<TrackInfo *> _trackInfos;
};