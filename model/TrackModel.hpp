//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_TRACKMODEL_H
#define SEQTRUAN_TRACKMODEL_H

#endif //SEQTRUAN_TRACKMODEL_H

#include "Singleton.hpp"
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

class TrackFrameInfo {
public:
    int idx;
    int holdCount;
    int startIdx;
//    int idx;

    QImage *payLoad;
    int startFrameIdx = 0;

//    TrackFrame *trackFrame;
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
                        trackFrameInfo->trackInfoIdx = trackInfo->idx;
                        trackFrameInfo->payLoad = img;
                        trackFrameInfo->idx = trackInfo->trackFrameInfos->size();
                        trackFrameInfo->startFrameIdx = trackFrameInfo->idx + 1;
                        trackInfo->trackFrameInfos->push_back(trackFrameInfo);
                    }
                }
        }
        if (sizeof(trackInfo->trackFrameInfos) > sequencePlayback->endFrameIdx) {
            sequencePlayback->endFrameIdx = sizeof(trackInfo->trackFrameInfos);
        }
        newTrackInfo = trackInfo;
        Evt()._().dis(TrackModelEvent_NEW_TRACK);
//    Evt::_().dis(TrackModelEvent_NEW_TRACK,trackInfo);
        newTrackInfo = NULL;
//    Evt::add("type",[=](){this->func1();});
//    Evt_dis("type")
//    Evt::add("type2",std::bind([](TrackModel *self) {self->func1();},this));
//    Evt::dis("type2");
    };


    TrackInfo *newTrackInfo;

    void setZoomLevel(int lv) {
        //todo
//    Evt_dis(TrackModelEvent::SET_ZOOM_LEVEL);
    }

    void relayout(int trackInfoIdx, int trackFrameInfoIdx) {
        //fixme

//        TrackInfo *trackInfo = _trackInfos->at(trackInfoIdx);
//        TrackFrameInfo *trackFrameInfo = trackInfo->trackFrameInfos->at(trackFrameInfoIdx);
//        TrackFrame *trackFrame = trackFrameInfo->trackFrame;
//
//        int changeWidth = trackFrame->changeWidth;
//        trackFrame->changeWidth = 0;
//        if (trackFrame->isPressRightButton) {
//            TrackFrame *preTf = trackFrame;
//            TrackFrame *tf;
//            for (int i = trackFrameInfo->idx + 1; i < trackInfo->trackFrameInfos->size(); i++) {
//                tf = trackInfo->trackFrameInfos->at(i)->trackFrame;
//                _setX(tf, preTf->x() + preTf->width());
//                TrackFrameInfo *tfInfo = getTrackFrameInfo(tf->trackInfoIdx, tf->trackFrameInfoIdx);
//                tfInfo->startFrameIdx += (changeWidth / frameWidth);
//                preTf = tf;
//            }
//            if (trackFrameInfo->idx + 1 < trackInfo->trackFrameInfos->size())
//                _setWidth(tf->parentWidget(), tf->x() + tf->width() + 40);
//            else {
//                _setWidth(trackFrame->parentWidget(), trackFrame->x() + trackFrame->width() + 40);
//            }
//        }
//        else if (trackFrame->isPressLeftButton) {
//            trackFrame->isPressLeftButton = false;
//            _setX(trackFrame, trackFrame->x() + changeWidth);
//            trackFrame->isPressLeftButton = true;
//            if (trackFrame->idx > 0) {
//                TrackFrame *preTrackFrame = trackInfo->trackFrameInfos->at(trackFrame->idx - 1)->trackFrame;
//                if (changeWidth > 0) {
//                    preTrackFrame->setHoldFrameCount(preTrackFrame->holdFrameCount + 1, 0);
//                }
//                else {
//                    if (preTrackFrame->holdFrameCount > 1) {
//                        preTrackFrame->setHoldFrameCount(preTrackFrame->holdFrameCount - 1, 0);
//                    }
//                    else {//todo Á¬Ðø¸²¸Ç¼¸Ö¡
////                    print('to delete preTrackFrame')
////                    Event.add(ActionEvent.RELEASE_TRACK_FRAME_LEFT_BUTTON, self.deletePreTrackFrame)
////                    self.deleteTrackFrame = preTrackFrame
//                    }
//                }
//
//            }
//        }
    }

    TrackInfo *getTrackInfo(int tIdx) { return _trackInfos->at(tIdx); }

    TrackFrameInfo *getTrackFrameInfo(int tIdx, int tfIdx) { return getTrackInfo(tIdx)->trackFrameInfos->at(tfIdx); }

    int frameWidth = 40;
    SequencePlayback *sequencePlayback;
    AudioPlayback *audioPlayback;
private:
    vector<TrackInfo *> *_trackInfos;

};