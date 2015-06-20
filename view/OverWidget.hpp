#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_HEADBUTTON_H
#define SEQTRUAN_HEADBUTTON_H

#include "view/UI.hpp"

#define over(widget, e, func)  widget->add(e, [this] { this->func(); });
#define paintEvent_ "paintEvent"
#define mousePressEvent_ "mousePressEvent"
#define mouseMoveEvent_ "mouseMoveEvent"
#define mouseReleaseEvent_ "mouseReleaseEvent"

template<class QCLS>
class OverWidget : public QCLS {
public:
    OverWidget(QWidget *parent = 0) : QCLS(parent) { };

    template<typename Observer>
    void add(const string &event, Observer &&observer) {
        _funcs[event] = forward<function<void()>>(observer);
    }

    bool isCustomQss = false;
private:
    void dis(const string event) {
        if (_funcs.find(event) != _funcs.end())
            _funcs.at(event)();
    }


protected:
//    virtual void setObjectName(const QString &name) override {
//        this->QCLS::setObjectName(name);
//        isCustomQss = true;
//    };

    virtual void mousePressEvent(QMouseEvent *mouseEvent) override { dis(mousePressEvent_); };

    virtual void mouseMoveEvent(QMouseEvent *mouseEvent) override { dis(mouseMoveEvent_); };

    virtual void mouseReleaseEvent(QMouseEvent *mouseEvent) override { dis(mouseReleaseEvent_); };

    virtual void paintEvent(QPaintEvent *qPaintEvent) override {
        if (isCustomQss) {
            QStyleOption opt;
            opt.init(this);
            QPainter p(this);
            style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
        }

        dis(paintEvent_);
    };

    map<string, function<void()>> _funcs;
};


#endif //SEQTRUAN_HEADBUTTON_H

