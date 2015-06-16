//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_TRACKMODEL_H
#define SEQTRUAN_TRACKMODEL_H

#endif //SEQTRUAN_TRACKMODEL_H

#include "Singleton.h"

class TrackModel :public Singleton<TrackModel>{
public:
//    static TrackModel &_() {
//        static TrackModel instance;
//        return instance;
//    }

    void newTrack();

//private:
//    TrackModel() { };
//
//    TrackModel(TrackModel const &) = delete;
//
//    void operator=(TrackModel const &) = delete;
};
//
//class TrackModel {
//public:
//    static TrackModel &_() {
//        static TrackModel instance;
//        return instance;
//    }
//
//    void newTrack();
//
//private:
//    TrackModel() { };
//
//    TrackModel(TrackModel const &) = delete;
//
//    void operator=(TrackModel const &) = delete;
//};
////