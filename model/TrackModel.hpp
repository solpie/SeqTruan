//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_TRACKMODEL_H
#define SEQTRUAN_TRACKMODEL_H

#endif //SEQTRUAN_TRACKMODEL_H

#include "utils/Singleton.hpp"
#include <functional>
#include <vector>
#include "events/Event.hpp"
#include <QtCore/qstring.h>
//#include "view/timeline/TrackFrame.hpp"
//#include "view/timeline/Track.hpp"
#include "model/playback/SequencePlayback.hpp"
#include "model/playback/AudioPlayback.hpp"
//template<typename P>
//class PayLoad {
//public:
//    P get() {
//        return this;
//    };
//};

#include "TrackInfo.hpp"
#include "TrackFrameInfo.hpp"

//class TrackInfo {
//public:
//    TrackInfo(QString name) {
//        this->name = name;
//        trackFrameInfos = new vector<TrackFrameInfo *>();
//    };
//    QString name;
//    vector<TrackFrameInfo *> *trackFrameInfos;
//    int startIdx;
//    int idx;
//
//    int getCurTrackFrameIdx() {
//        return _trackFrameIdx;
//    };
////    Track *track;
////    void updateTrackInfo(TrackInfo *trackInfo,int... p);
//private:
//    int _trackFrameIdx;
//
//};

#include <iostream>

//#include "view/timeline/Track.hpp"
class TrackModel {
public:
    TrackModel() {
        sequencePlayback = new SequencePlayback();
        audioPlayback = new AudioPlayback();
        _trackInfos = new vector<TrackInfo *>();
    }

    void newTrack(QString name, QString dirname = "") {
//    Evt_add("type", func1);
        TrackInfo *trackInfo = new TrackInfo(name);
        trackInfo->idx = _trackInfos->size();
        _trackInfos->push_back(trackInfo);
        if (dirname != "") {
            QDir dir(dirname);
            dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoSymLinks);
            const QFileInfoList fileinfolist = dir.entryInfoList();
                    foreach(const QFileInfo &fi, fileinfolist) {
                    if (fi.baseName() == "." || fi.baseName() == ".." || fi.baseName() == "") {
                        continue;
                    }
                    if (fi.isDir() && fi.isReadable()) {
                        // This is the conditional for recursion
//                walk( fi.absoluteFilePath() );
                    }
                    else {
                        // This is where you might call your encrypting function
                        qDebug() << "Image file: " << fi.absoluteFilePath();
                        QImage *img = new QImage(fi.absoluteFilePath());
                        TrackFrameInfo *trackFrameInfo = new TrackFrameInfo();
                        trackFrameInfo->setTrackInfoIdx(trackInfo->idx);
                        trackFrameInfo->payLoad = img;
                        trackFrameInfo->setIdx(trackInfo->trackFrameInfos->size());
                        trackFrameInfo->setStartFrame(trackFrameInfo->getIdx() + 1);
                        trackFrameInfo->setHoldFrame(1);
                        trackInfo->trackFrameInfos->push_back(trackFrameInfo);
                    }
                }
        }
        if (sizeof(trackInfo->trackFrameInfos) > sequencePlayback->endFrameIdx) {
            sequencePlayback->endFrameIdx = sizeof(trackInfo->trackFrameInfos);
        }
        Evt_dis(TrackModelEvent::NEW_TRACK, trackInfo);
    };


    void setZoomLevel(int lv) {
        //todo
//    Evt_dis(TrackModelEvent::SET_ZOOM_LEVEL);
    }

    vector<TrackFrameInfo *> *getRenderFrame(int frameIdx) {
        vector<TrackFrameInfo *> *images = new vector<TrackFrameInfo *>;
        for (TrackInfo *trackInfo:*_trackInfos) {
            if (!trackInfo->visible)
                continue;
            int trackFrameIdx = frameIdx - trackInfo->getStartFrame() + 1;
            for (TrackFrameInfo *trackFrameInfo:*trackInfo->trackFrameInfos) {
                qDebug() << this << "getRenderFrame" << trackFrameInfo->getIdx();
                if (trackFrameIdx >= trackFrameInfo->getStartFrame() &&
                    trackFrameIdx <= trackFrameInfo->getEndFrame()) {
                    //todo 实现链表查找
//                    return new QPixmap(QPixmap::fromImage(trackFrameInfo->payLoad));
                    //todo 透明度
//                    trackFrameInfo->payLoad->setAlphaChannel()
                    trackFrameInfo->opacity = trackInfo->getOpacity();
                    images->push_back(trackFrameInfo);
                    break;
                }
            }
        }
        return images;
//        return nullptr;
    }

    TrackInfo *getTrackInfo(int tIdx) { return _trackInfos->at(tIdx); }

    TrackFrameInfo *getTrackFrameInfo(int tIdx, int tfIdx) { return getTrackInfo(tIdx)->trackFrameInfos->at(tfIdx); }

    int frameWidth = 40;

    SequencePlayback *sequencePlayback;
    AudioPlayback *audioPlayback;
private:
    vector<TrackInfo *> *_trackInfos;

};