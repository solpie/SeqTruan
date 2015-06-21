#pragma once
//
// Created by manoyuria on 2015/6/21.
//

#include <QtGui/qimage.h>

#ifndef SEQTRUAN_TRACKFRAMEINFO_HPP
#define SEQTRUAN_TRACKFRAMEINFO_HPP

#endif //SEQTRUAN_TRACKFRAMEINFO_HPP
class TrackFrameInfo {
public:
    int idx;
    int holdCount;
    int startIdx;
//    int idx;

    QImage *payLoad;
    int startFrameIdx = 0;
    int endFrameIdx = 0;

//    TrackFrame *trackFrame;
    int trackInfoIdx;
//    auto *payLoad;
//    PayLoad payLoad;
};