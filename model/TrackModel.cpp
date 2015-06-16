//
// Created by toramisu on 2015/6/16.
//

#include <iostream>

#include "TrackModel.h"
#include "events/subject.h"
#include "events/Event.h"
void foo(TrackModel *i)
{
    i->func1();
}
void TrackModel::newTrack() {

    Subject<std::string> s;
    s.registerObserver("ORANGE", std::bind(foo, this));
//    __.registerObserver("GREEN", std::bind(this->func1, 0));

//    __.registerObserver("GREEN", &this->func1);
//    __.notify("GREEN");
//    __.notify("RED");
//    __.notify("ORANGE");

//    Evt::_().add("func", std::bind(foo, this));
//    Evt::_().dis("func");

    Evt::add("func", std::bind(foo, this));
    Evt::dis("func");

//    functors.push_back([&] { return 100; });
//    functors.push_back([&] { return 10; });
};
void TrackModel::func1(){
    std::cout << "foo( "  << " )\n";
};