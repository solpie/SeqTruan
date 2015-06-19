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
using namespace std;


//template<class EventType>
//class Evt  {
//public:
//    using EventHandler = std::function<void(void ...)>;
//
//    void add(EventType &&event, EventHandler &&handler) {
//        _handlers[std::move(event)].push_back(std::forward<EventHandler>(handler));
//    }
//
//    void dis(const EventType &event, void &&... args) {
//        for (const auto &handler: Evt::_handlers.at(event)) {
//            handler(std::forward<void>(args)...);
//        }
//    }
//
//private:
//    std::map<EventType, std::vector<EventHandler>> _handlers;
//
//};

class Evt : public Singleton<Evt> {
public:
    Evt() = default;

    template<typename Observer>
    void add(const string &event, Observer &&observer) {
        _observers[event].push_back(forward<function<void()>>(observer));
    }

    void dis(const string &event) const {
        for (const auto &obs : _observers.at(event))
            obs();
    }

    // disallow copying and assigning
    Evt(const Evt &) = delete;

    Evt &operator=(const Evt &) = delete;

private:
    map<string, vector<function<void()>>> _observers;
};


#define Evt_add(type, func) Evt::_().add(type, [this] {func();});
#define Evt_dis(type) Evt::_().dis(type);
