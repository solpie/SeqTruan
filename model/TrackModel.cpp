//
// Created by toramisu on 2015/6/16.
//

#include <iostream>
#include <view/timeline/Track.h>

TrackModel::TrackModel() {
    sequencePlayback = new SequencePlayback();
    audioPlayback = new AudioPlayback();
    _trackInfos = new vector<TrackInfo *>();
}

void TrackModel::newTrack(QString name, QString dirname = "") {
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


void TrackModel::relayout(int trackInfoIdx, int trackFrameInfoIdx) {
    TrackInfo *trackInfo = _trackInfos->at(trackInfoIdx);
    TrackFrameInfo *trackFrameInfo = trackInfo->trackFrameInfos->at(trackFrameInfoIdx);
    TrackFrame *trackFrame = trackFrameInfo->trackFrame;

    int changeWidth = trackFrame->changeWidth;
    trackFrame->changeWidth = 0;
    if (trackFrame->isPressRightButton) {
        for (int i = trackFrameInfo->idx+1; i < trackInfo->trackFrameInfos->size(); i++) {
            TrackFrame *tf = trackInfo->trackFrameInfos->at(i)->trackFrame;
//            _setX(tf, tf->x() + changeWidth);
            tf->move(tf->x() + changeWidth, tf->y());
            _setWidth(tf->parentWidget(), tf->parentWidget()->x() + tf->parentWidget()->width());
            TrackFrameInfo *tfInfo = getTrackFrameInfo(tf->trackInfoIdx, tf->trackFrameInfoIdx);
            tfInfo->startFrameIdx += (changeWidth / frameWidth);
        }
    }
}
