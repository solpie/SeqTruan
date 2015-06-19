#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_HEADBUTTON_H
#define SEQTRUAN_HEADBUTTON_H

#include "view/UI.h"

#define paintEvent_ "paintEvent"
#define over(widget, e, func)  widget->add(e, [this] { this->func(); });

class OverWidget : public QWidget {
public:
    OverWidget(QWidget *parent);

    template<typename Observer>
    void add(const string &event, Observer &&observer) {
        _observers[event].push_back(forward<function<void()>>(observer));
    }

private:
    void dis(const string event) {
        for (const auto &obs : _observers.at(event))
            obs();
    }

    virtual void paintEvent(QPaintEvent *qPaintEvent) override;

    map<string, vector<function<void()>>> _observers;
};


#endif //SEQTRUAN_HEADBUTTON_H
