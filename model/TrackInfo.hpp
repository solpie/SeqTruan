#pragma once
//
// Created by manoyuria on 2015/6/21.
//

#include "TrackFrameInfo.hpp"

#ifndef SEQTRUAN_TRACKINFO_HPP
#define SEQTRUAN_TRACKINFO_HPP

#endif //SEQTRUAN_TRACKINFO_HPP
using namespace std;

class TrackInfo {
public:
    TrackInfo(QString name) {
        this->name = name;
        trackFrameInfos = new vector<TrackFrameInfo *>();
    };
    QString name;
    vector<TrackFrameInfo *> *trackFrameInfos;
    int idx;

    int getCurTrackFrameIdx() {
        return _trackFrameIdx;
    };

    int getStartFrame() {
        return _startFrame;
    }

    void setStartFrame(int v) {
        _startFrame = v;
    }
protected:
    int _startFrame;
private:
    int _trackFrameIdx;

};