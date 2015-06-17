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

class TrackModel :public Singleton<TrackModel>{
public:

    void newTrack();

    void func1();

};