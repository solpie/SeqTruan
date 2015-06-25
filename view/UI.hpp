//
// Created by manoyuria on 2015/6/18.
//
#pragma once
#ifndef SEQTRUAN_UI_H
#define SEQTRUAN_UI_H

#include "Theme.hpp"
#include "events/Event.hpp"
#include "events/TrackModelEvent.hpp"
#include <functional>
#include "QApplication"
#include "Qt"
#include "QStyle"
#include "QtCore"
#include "QPoint"
#include "QFile"
#include "QWidget"
#include "QOpenGLWidget"
#include "QOpenGLFunctions"
#include "QLabel"
#include "QCheckBox"
#include "QVBoxLayout"
#include "QPushButton"
#include "QSplitter"
#include "QScrollBar"
#include "QComboBox"
#include "QPainter"
#include "QCursor"
#include "QPixmap"
#include "QPen"
#include "QBrush"
#include "QPainterPath"
#include "QColor"
#include "QLinearGradient"
/////////////////////
#include "view/OverWidget.hpp"
#include "model/App.hpp"
//////////////////////////////////////////////// qt method
#define _app App()._()
#define _setMouseTransparent(widget) widget->setAttribute(Qt::WA_TransparentForMouseEvents, true)
#define _setColor1(widget, color) qwidget->setAutoFillBackground(True)
#define _localPos mapFromGlobal(QCursor::pos())

class UI {
public:
    static void setWidth(QWidget *w, int width) {
        w->resize(width, w->height());
    }
    static void setHeight(QWidget *w, int height) {
        w->resize(w->width(),height);
    }

    static void setX(QWidget *w, int x) {
        w->move(x, w->y());
    }

    static void setY(QWidget *w, int y) {
        w->move(w->x(), y);
    }

    static void setQss(QWidget *w, QString alias, QString objName = "") {
        QFile f(alias);
        f.open(QIODevice::ReadOnly);
        QByteArray ba = f.readAll();
        if (objName != "") {
//            (OverWidget<void>*)&w.isC
//            OverWidget<QWidget> *ow = (OverWidget<QWidget>*)&w;
//            auto ow = &w;
//            ow->isCustomQss=true;
//            ow.isCustomQss=true;
//            if(w->objectName()== "OverWidget")
            w->setObjectName(objName);
        }
        w->setStyleSheet(ba.data());
        f.close();
    }
};

//def fillColor(qwidget, color):
//qwidget.setAutoFillBackground(True)
//p = qwidget.palette()
//p.setColor(qwidget.backgroundRole(), QColor(color))
//qwidget.setPalette(p)
///////////////////////////////////////////////////////////////////////
class DragWidget : public QWidget {
public:
    DragWidget(QWidget *parent) : QWidget(parent) {
    }

private:
    bool _isPress;
    int _lastX;
    int _lastY;
protected:
    std::function<void()> *exPressFunc = NULL;

    virtual void mousePressEvent(QMouseEvent *mouseEvent) {
        _isPress = true;
//        if (exPressFunc != NULL) {
//            (&exPressFunc)();
//        }
    }

    virtual void mouseMoveEvent(QMouseEvent *mouseEvent) {

    }

    virtual void mouseReleaseEvent(QMouseEvent *mouseEvent) {
        _isPress = false;

    }
};

#endif //SEQTRUAN_UI_H

