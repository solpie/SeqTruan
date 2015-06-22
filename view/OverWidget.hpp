#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_HEADBUTTON_H
#define SEQTRUAN_HEADBUTTON_H

#include "view/UI.hpp"

#define over(widget, type, func)  widget->add(type, [this] (void* e1){ this->func(e1); });
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
        _funcs[event] = forward<function<void(void*)>>(observer);
    }

    bool isCustomQss = false;
private:
    void dis(const string event, void *e = nullptr) {
        if (_funcs.find(event) != _funcs.end())
            _funcs.at(event)(e);
    }


protected:
//    virtual void setObjectName(const QString &name) override {
//        this->QCLS::setObjectName(name);
//        isCustomQss = true;
//    };

    virtual void mousePressEvent(QMouseEvent *e) override { dis(mousePressEvent_, e); };

    virtual void mouseMoveEvent(QMouseEvent *e) override { dis(mouseMoveEvent_, e); };

    virtual void mouseReleaseEvent(QMouseEvent *e) override { dis(mouseReleaseEvent_, e); };

    virtual void paintEvent(QPaintEvent *e) override {
        if (isCustomQss) {
            QStyleOption opt;
            opt.init(this);
            QPainter p(this);
            style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
        }
        dis(paintEvent_,e);
    };

    map<string, function<void(void*)>> _funcs;
};


#endif //SEQTRUAN_HEADBUTTON_H

