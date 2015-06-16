//
// Created by toramisu on 2015/6/16.
//
#pragma once

#ifndef SEQTRUAN_ACTIONEVENT_H
#define SEQTRUAN_ACTIONEVENT_H

#endif //SEQTRUAN_ACTIONEVENT_H

#include "model/Singleton.h"
#include "QString"
#include <vector>
struct Subscription
{
    void*                   observer;
    string                  event;
    /*  u_u  */             action;
};

class Event : public Singleton<Event> {
private:
    vector<Subscription>    subscriptions;
public:

    void init(){};

    void add(QString type,std::function<void()> func){

    };

    void dis(QString type);

    void del(QString type);

};

const enum Actions{
NEW_TRACK,
NEW_TRACK1
};