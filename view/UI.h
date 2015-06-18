//
// Created by manoyuria on 2015/6/18.
//
#pragma once
#ifndef SEQTRUAN_UI_H
#define SEQTRUAN_UI_H

#include "Theme.h"
#include <c++/functional>
#include "QWidget"
#include "Qt"
#define setX(widget, x) widget->move(x,widget->y())
#define setY(widget, y) widget->move(widget->x(),y)
#define setMouseTransparent(widget) widget->setAttribute(Qt::WA_TransparentForMouseEvents, true)
class DragWidget : public QWidget {
public:
    DragWidget(QWidget *parent) : QWidget(parent) {
    }

private:
    bool _isPress;
    int _lastX;
    int _lastY;
protected:
    std::function<void()> &&exPressFunc = NULL;

    virtual void mousePressEvent(QMouseEvent *mouseEvent) {
        _isPress = true;
        if (exPressFunc != NULL) {
            exPressFunc();
        }
    }

    virtual void mouseMoveEvent(QMouseEvent *mouseEvent) {

    }

    virtual void mouseReleaseEvent(QMouseEvent *mouseEvent) {
        _isPress = false;

    }
};

#endif //SEQTRUAN_UI_H

