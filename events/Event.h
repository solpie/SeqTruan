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
#include "ActionEvent.h"
#include "PlaybackEvent.h"
#include "TrackModelEvent.h"

using namespace std;



class Evt : public Singleton<Evt> {
public:
    Evt() = default;

    template<typename Observer>
    void add(const string &event, Observer &&observer) {
        _observers[event].push_back(forward<function<void()>>(observer));
    }

//    template<typename Param>
//    void dis(const string &event, Param *p) const {
//        if (_observers.find(event) != _observers.end())
//            for (const auto &obs : _observers.at(event)) {
//                std::bind(obs,p);
//                obs();
//            }
//    }
    void dis(const string &event) const {
        if (_observers.find(event) != _observers.end())
            for (const auto &obs : _observers.at(event)) {
                obs();
            }
    }

    // disallow copying and assigning
    Evt(const Evt &) = delete;

    Evt &operator=(const Evt &) = delete;

private:
    map<string, vector<function<void()>>> _observers;
};


#define Evt_add(type, func) Evt::_().add(type, [this] {func();});
#define Evt_dis(type) Evt::_().dis(type);
