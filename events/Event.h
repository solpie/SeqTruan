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


//template<typename Event>
//class Subject {
//public:
//    Subject() = default;
//
//    template<typename Observer>
//    void registerObserver(const Event &event, Observer &&observer) {
//        observers_[event].push_back(forward<Observer>(observer));
//    }
//
//    void notify(const Event &event) const {
//        for (const auto &obs : observers_.at(event))
//            obs();
//    }
//
//    // disallow copying and assigning
//    Subject(const Subject &) = delete;
//
//    Subject &operator=(const Subject &) = delete;
//
//private:
//    map<Event, vector<function<void()>>> observers_;
//};

//class Evt : public Singleton<Evt> {
////private:
////    Subject<string> __;
//public:
//    Subject<string> __;
//
//    static void add(const string event, auto &&observer) {
//        Evt::_().__.registerObserver(event, observer);
//    }
//
//    static void dis(const string event) {
//        Evt::_().__.notify(event);
//    }
//};

class Evt : public Singleton<Evt> {
public:
    Evt() = default;

    template<typename Observer>
    void _add(const string &event, Observer &&observer) {
        _observers[event].push_back(forward<function<void()>>(observer));
    }

    void _dis(const string &event) const {
        for (const auto &obs : _observers.at(event))
            obs();
    }

    static void add(const string event, auto &&observer) {
        Evt::_()._add(event, observer);
    }

    static void dis(const string event) {
        Evt::_()._dis(event);
    }

    // disallow copying and assigning
    Evt(const Evt &) = delete;

    Evt &operator=(const Evt &) = delete;

private:
    map<string, vector<function<void()>>> _observers;
};


#define Evt_add(type, func) Evt::_()._add(type, [this] {func();});
#define Evt_dis(type) Evt::dis(type);
