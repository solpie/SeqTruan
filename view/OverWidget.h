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

template<class QCLS>
class OverWidget : public QCLS {
public:
    template<typename Observer>
    void add(const string &event, Observer &&observer) {
        _funcs[event] = forward<function<void()>>(observer);
    }

private:
    void dis(const string event) {
        if (_funcs.find(event) != _funcs.end())
            _funcs.at(event)();
    }

protected:

    virtual void mousePressEvent(QMouseEvent *mouseEvent) override { dis(mousePressEvent_); };

    virtual void mouseMoveEvent(QMouseEvent *mouseEvent) override { dis(mouseMoveEvent_); };

    virtual void mouseReleaseEvent(QMouseEvent *mouseEvent) override { dis(mouseReleaseEvent_); };

    virtual void paintEvent(QPaintEvent *qPaintEvent) override { dis(paintEvent_); };

    map<string, function<void()>> _funcs;
};


#endif //SEQTRUAN_HEADBUTTON_H

