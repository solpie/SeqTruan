//
// Created by toramisu on 2015/6/16.
//

#include <iostream>

#include "TrackModel.h"
#include "events/Event.h"
//#define _func(func) std::bind([=](TrackModel *self) {self->func();},this)

void TrackModel::newTrack() {
//    Evt::add("func", std::bind(foo, this));



//    Evt::add("func", std::bind([=](TrackModel *self) {
//        self->func1();
//    }, this));
//    Evt::add("type", _func(func1));
    Evt_add("type",func1);
//    Evt::add("func",this->func1);
//    Evt::add("func", _CRTIMP(this->func1));
//    Evt::add("func", std::bind(foo, this));
//    Evt::dis("func");
    Evt_dis("type");

};

void TrackModel::func1() {
//    qDebug()
};