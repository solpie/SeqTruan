//
// Created by toramisu on 2015/6/16.
//

#include <iostream>

#include "TrackModel.h"
#include "events/Event.h"
//#define _func(func) std::bind([=](TrackModel *self) {self->func();},this)

void TrackModel::newTrack() {
    Evt_add("type",func1);
//    Evt::add("type",[=](){this->func1();});
//    Evt_dis("type")
//    Evt::add("type2",std::bind([](TrackModel *self) {self->func1();},this));
//    Evt::dis("type2");
};

void TrackModel::func1() {
//    qDebug()
    printf("ii");
};