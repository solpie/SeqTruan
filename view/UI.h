//
// Created by manoyuria on 2015/6/18.
//
#pragma once
#ifndef SEQTRUAN_UI_H
#define SEQTRUAN_UI_H

#include "Theme.h"
#include "events/Event.h"
#include "events/TrackModelEvent.h"
#include <functional>
#include "QApplication"
#include "Qt"
#include "QStyle"
#include "QtCore"
#include "QFile"
#include "QWidget"
#include "QLabel"
#include "QCheckBox"
#include "QVBoxLayout"
#include "QPushButton"
#include "QSplitter"
#include "QScrollBar"
#include "QComboBox"
#include "QPainter"
#include "QPixmap"
#include "QPen"
#include "QBrush"
#include "QPainterPath"
#include "QColor"
#include "QLinearGradient"
/////////////////////
#include "OverWidget.h"
//////////////////////////////////////////////// qt method
#define _setX(widget, x) widget->move(x,widget->y())
#define _setY(widget, y) widget->move(widget->x(),y)
#define _setHeight(widget, height) widget->resize(widget->width(),height)
#define _setWidth(widget, width) widget->resize(width,widget->height())
#define _setMouseTransparent(widget) widget->setAttribute(Qt::WA_TransparentForMouseEvents, true)
#define setColor1(widget, color) qwidget->setAutoFillBackground(True)

#define _setQss(widget, alias) \
do { \
QFile f(alias);\
f.open(QIODevice::ReadOnly); \
QByteArray ba = f.readAll(); \
(widget)->setStyleSheet(ba.data()); \
f.close(); \
} while(false);


class UI : public Singleton<UI> {
public:
//    static void _setQss(QWidget *w, const QString alias) {
//        QFile f(alias);
//        f.open(QIODevice::ReadOnly);
//        QByteArray ba = f.readAll();
////        qDebug()<<ba.data();
//        w->setStyleSheet(ba.data());
//        f.close();
//
////        QFile f(":/qss_scrollbar");
////        f.open(QIODevice::ReadOnly);
////        QByteArray ba = f.readAll();
////        vScrollBar->setStyleSheet(ba.data());
////        f.close();
//    }
    QString getQss(const QString alias) {
        QFile f(alias);
        f.open(QIODevice::ReadOnly);
        QByteArray ba = f.readAll();
        f.close();
        QString s = ba.data();
//        qDebug()<<s;

        return ba.data();
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

