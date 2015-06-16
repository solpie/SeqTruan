//
// Created by manoyuria on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_EVENT_H
#define SEQTRUAN_EVENT_H

#endif //SEQTRUAN_EVENT_H

#include "model/Singleton.h"
#include "subject.h"

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