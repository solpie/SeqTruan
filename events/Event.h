//
// Created by manoyuria on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_EVENT_H
#define SEQTRUAN_EVENT_H

#endif //SEQTRUAN_EVENT_H

#include "model/Singleton.h"
#include <functional>
#include <map>
#include <vector>
#include <utility> // for forward

using namespace std;


template<typename Event>
class Subject {
public:
    Subject() = default;

    template<typename Observer>
    void registerObserver(const Event &event, Observer &&observer) {
        observers_[event].push_back(forward<Observer>(observer));
    }

    template<typename Observer>
    void registerObserver(Event &&event, Observer &&observer) {
        observers_[move(event)].push_back(forward<Observer>(observer));
    }

    void notify(const Event &event) const {
        for (const auto &obs : observers_.at(event))
            obs();
    }

    // disallow copying and assigning
    Subject(const Subject &) = delete;

    Subject &operator=(const Subject &) = delete;

private:
    map<Event, vector<function<void()>>> observers_;
};

class Evt : public Singleton<Evt> {
//private:
//    Subject<string> __;
public:
    Subject<string> __;

    template<typename Observer>
    static void add(const string event, Observer &&observer) {
        Evt::_().__.registerObserver(event, observer);
    }

    static void dis(const string event) {
        Evt::_().__.notify(event);
    }
};




#define _func(func) std::bind([](TrackModel *self) {self->func();},this)
#define Evt_add(type,func) Evt::add(type, _func(func));
#define Evt_dis(type) Evt::dis(type);