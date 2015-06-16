//
// Created by toramisu on 2015/6/16.
//

#include <iostream>
#include "TrackModel.h"
#include "events/subject.h"
void foo(TrackModel *i)
{
    i->func1();
}
void TrackModel::newTrack() {

    Subject<std::string> s;
    s.registerObserver("ORANGE", std::bind(foo, this));
//    s.registerObserver("GREEN", std::bind(this->func1, 0));

//    s.registerObserver("GREEN", &this->func1);
//    s.notify("GREEN");
//    s.notify("RED");
    s.notify("ORANGE");
//    functors.push_back([&] { return 100; });
//    functors.push_back([&] { return 10; });
};
void TrackModel::func1(){
    std::cout << "foo( "  << " )\n";
};