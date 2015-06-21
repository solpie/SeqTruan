//
// Created by manoyuria on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_EVENT_H
#define SEQTRUAN_EVENT_H

#endif //SEQTRUAN_EVENT_H

#include "utils/Singleton.hpp"
#include <functional>
#include <map>
#include <vector>
#include <utility> // for forward
#include "ActionEvent.hpp"
#include "PlaybackEvent.hpp"
#include "TrackModelEvent.hpp"

using namespace std;

#include "SequencePlaybackEvent.hpp"

template<typename EVENT_CLS>
class Event {
public:
    Event() = default;

    template<typename Observer>
    void add(const string &event, Observer &&observer) {
        _observers[event].push_back(forward<function<void(EVENT_CLS *)>>(observer));
    }

    void dis(const string &event, EVENT_CLS *e) const {
        if (_observers.find(event) != _observers.end())
            for (const auto &obs : _observers.at(event)) {
                obs(e);
            }
    }

    // disallow copying and assigning
    Event(const Event &) = delete;

    Event &operator=(const Event &) = delete;

private:
    map<string, vector<function<void(EVENT_CLS *)>>> _observers;
};

class Evt : public Singleton<Evt> {
public:
    Evt() = default;

    template<typename Observer>
    void add(const string &event, Observer &&observer) {
        _observers[event].push_back(forward<function<void()>>(observer));
    }

    void dis(const string &event) const {
        if (_observers.find(event) != _observers.end())
            for (const auto &obs : _observers.at(event)) {
                obs();
            }
    }

    void init() {
        seq = new Event<SequencePlaybackEvent>();
        trackModelEvent = new Event<TrackModelEvent>();
    }

    // disallow copying and assigning
    Evt(const Evt &) = delete;

    Evt &operator=(const Evt &) = delete;

    Event<SequencePlaybackEvent> *seq;
    Event<TrackModelEvent> *trackModelEvent;
private:
    map<string, vector<function<void()>>> _observers;
};


#define Evt_add(type, func) Evt::_().add(type, [this] {func();});
#define Evt_dis(type) Evt::_().dis(type);
