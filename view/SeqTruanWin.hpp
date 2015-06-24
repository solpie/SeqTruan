//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_SEQTRUANWIN_H
#define SEQTRUAN_SEQTRUANWIN_H

#endif //SEQTRUAN_SEQTRUANWIN_H

#include "view/viewport/ViewPort.hpp"
#include "view/UI.hpp"
#include "view/timeline/Timeline.hpp"
#include "view/Popup.hpp"

class SeqTruanWin : public QMainWindow {
public:
    SeqTruanWin(QWidget *parent = 0) {
        resize(1440, 1056);

        vSplitter = new QSplitter(Qt::Vertical, this);
        vSplitter->resize(width(), height());
        vSplitter->setOpaqueResize(false);
        _viewport = new ViewPort(vSplitter);
        _timeline = new Timeline(vSplitter);

        setStyleSheet("background:#484848");
        qDebug() << "inited SeqTruanWin";

        popup = new Popup(this);
        popup->hide();

    }

    virtual ~SeqTruanWin() { }

private:

protected:
    virtual void resizeEvent(QResizeEvent *qResizeEvent) override {
        qDebug() << this << "resize window";
        vSplitter->resize(width(), height());
        _setY(_timeline,height()-_timeline->height());
        _setWidth(_timeline, width());
    }
    QSplitter *vSplitter;
    Popup *popup;
    ViewPort *_viewport;
    Timeline *_timeline;
    QPushButton *testBtn;
};
