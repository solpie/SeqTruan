//
// Created by manoyuria on 2015/6/18.
//
#pragma once
#ifndef SEQTRUAN_TRACKCURSOR_H
#define SEQTRUAN_TRACKCURSOR_H

#include "view/UI.hpp"
#include "model/App.hpp"

class FrameCursor : public DragWidget {
//没重绘的部分透明 The Q_OBJECT macro at the beginning of the class definition is necessary for all classes that define signals or slots
Q_OBJECT
public:
    FrameCursor(QWidget *parent = 0) : DragWidget(parent) {
        resize(60, 200);
        timeLabel = new QLabel("00:00:24", this);
        timeLabel->move(2, 10);
        timeLabel->resize(60, 20);
        _setMouseTransparent(this);
        Evt_add(ActionEvent::UPDATE_CURSOR, onUpdateCursor);
        Evt_add(ActionEvent::SCROLL_TIMELINE_HBAR, onScrollHBar);
        Evt_add(TrackModelEvent::SET_ZOOM_LEVEL, onUpdateZoom);

    }

    void onUpdateCursor(int *frameIdx) {
        setPosXbyIdx(*frameIdx);
    }

    void setPosXbyIdx(int idx) {
        int fw = _app.trackModel->frameWidth;
        int px = idx * fw - _hBarValue;
        if (px != x())
            UI::setX(this, px);
//        qDebug() << this << "setPosXbyIdx" << idx
//        << "posx" << x()
//        << "hBarValue" << _hBarValue;
    }

private:
    QLabel *timeLabel;
    int i;

    void onUpdateZoom(void *e) {
        setPosXbyIdx(_app.trackModel->sequencePlayback->frameIdx);
        update();
    }

protected:

    int _hBarValue = 0;

    void onScrollHBar(int *i) {
        _hBarValue = *i;
    }

    virtual void paintEvent(QPaintEvent *qPaintEvent) override {
        QPainter p(this);
        QPen pen;
        pen.setColor(QColor(TIMELINE_CURSOR_EDGE_COL));

        p.setPen(pen);
        p.drawLine(0, 0, 0, this->height());
        int frameWidth = _app.trackModel->frameWidth;
        p.drawLine(frameWidth, 0, frameWidth, this->height());
    }

    virtual void resizeEvent(QResizeEvent *e) override {

    }
};

#endif //SEQTRUAN_TRACKCURSOR_H

