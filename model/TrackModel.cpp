//
// Created by toramisu on 2015/6/16.
//

#include <iostream>

#include "TrackModel.h"
#include "events/Event.h"

void foo(TrackModel *i) {
    i->func1();
}

void func2(TrackModel *i) {
    i->func1();
}

void TrackModel::newTrack() {
    Evt::add("func", std::bind(foo, this));
    Evt::add("func", std::bind(func2, this));
    Evt::dis("func");
};

void TrackModel::func1() {
    std::cout << "foo( " << " )\n";
};