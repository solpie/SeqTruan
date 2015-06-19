#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_HEADBUTTON_H
#define SEQTRUAN_HEADBUTTON_H

#include "view/UI.h"

#define over(widget, e, func)  widget->add(e, [this] { this->func(); });
#define paintEvent_ "paintEvent"
#define mousePressEvent_ "mousePressEvent"
#define mouseMoveEvent_ "mouseMoveEvent"
#define mouseReleaseEvent_ "mouseReleaseEvent"

class OverWidget : public QWidget {
public:
    OverWidget(QWidget *parent) : QWidget(parent) { };

    template<typename Observer>
    void add(const string &event, Observer &&observer) {
        _observers[event].push_back(forward<function<void()>>(observer));
    }

private:
    void dis(const string event) {
        for (const auto &obs : _observers.at(event))
            obs();
    }

protected:

    virtual void mousePressEvent(QMouseEvent *mouseEvent) override { dis(mousePressEvent_); };

    virtual void mouseMoveEvent(QMouseEvent *mouseEvent) override { dis(mouseMoveEvent_); };

    virtual void mouseReleaseEvent(QMouseEvent *mouseEvent) override { dis(mouseReleaseEvent_); };

    virtual void paintEvent(QPaintEvent *qPaintEvent) override { dis(paintEvent_); };

    map<string, vector<function<void()>>> _observers;
};


#endif //SEQTRUAN_HEADBUTTON_H

