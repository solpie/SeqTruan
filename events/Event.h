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
#include <utility> // for std::forward

template<typename Event>
class Subject {
public:
    Subject() = default;

    template<typename Observer>
    void registerObserver(const Event &event, Observer &&observer) {
        observers_[event].push_back(std::forward<Observer>(observer));
    }

    template<typename Observer>
    void registerObserver(Event &&event, Observer &&observer) {
        observers_[std::move(event)].push_back(std::forward<Observer>(observer));
    }

    void notify(const Event &event) const {
        for (const auto &obs : observers_.at(event)) obs();
    }

    // disallow copying and assigning
    Subject(const Subject &) = delete;

    Subject &operator=(const Subject &) = delete;

private:
    std::map<Event, std::vector<std::function<void()>>> observers_;
};

class Evt : public Singleton<Evt> {
//private:
//    Subject<std::string> __;
public:
    Subject<std::string> __;

    template<typename Observer>
    static void add(const std::string event, Observer &&observer) {
        Evt::_().__.registerObserver(event, observer);
    }

    static void dis(const std::string event) {
        Evt::_().__.notify(event);
    }
};