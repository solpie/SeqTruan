//
// Created by toramisu on 2015/6/16.
//

#include <iostream>

#include "TrackModel.h"

TrackModel::TrackModel() {
    sequencePlayback = new SequencePlayback();
    audioPlayback = new AudioPlayback();
}

void TrackModel::newTrack(QString name, QString dirname = "") {
//    Evt_add("type", func1);
    TrackInfo *trackInfo = new TrackInfo(name);
    _trackInfos.push_back(trackInfo);
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
                    trackFrameInfo->payLoad = img;
                    trackInfo->frames.push_back(trackFrameInfo);
                    trackFrameInfo->frameIdx = trackInfo->frames.size();
                }
            }
    }
    if (sizeof(trackInfo->frames) > sequencePlayback->endFrameIdx) {
        sequencePlayback->endFrameIdx = sizeof(trackInfo->frames);
    }
    newTrackInfo = trackInfo;
    Evt::_().dis(TrackModelEvent_NEW_TRACK);
//    Evt::_().dis(TrackModelEvent_NEW_TRACK,trackInfo);
    newTrackInfo = NULL;
//    Evt::add("type",[=](){this->func1();});
//    Evt_dis("type")
//    Evt::add("type2",std::bind([](TrackModel *self) {self->func1();},this));
//    Evt::dis("type2");
};

void TrackModel::func1() {
//    qDebug()
    printf("ii");
};

void TrackModel::setZoomLevel(int lv) {
    //todo
//    Evt_dis(TrackModelEvent::SET_ZOOM_LEVEL);
}
