#pragma once
//
// Created by manoyuria on 2015/6/18.
//

#ifndef SEQTRUAN_TIMESTAMPBAR_H
#define SEQTRUAN_TIMESTAMPBAR_H

#include "view/UI.hpp"

class TimestampBar : public QWidget {
public:
    TimestampBar(QWidget *parent) : QWidget(parent) {

    }


protected:
    virtual void paintEvent(QPaintEvent *qPaintEvent) override {
        QPainter p(this);
        QPen pen(QColor(0x343434));
        p.setPen(pen);
        for (int i = 0; i < this->width(); i += TIMELINE_TRACK_FRAME_MAX_WIDTH) {
            p.drawLine(i, 15, i, this->height());
        }
    }

    bool isPress = false;

    virtual void mousePressEvent(QMouseEvent *mouseEvent) override {
        isPress = true;
        updateCursor();
    }

    void updateCursor() {
        int posX = mapFromGlobal(QCursor::pos()).x();
        int fw = App()._().trackModel->frameWidth;
        int frameIdx = (posX / fw);
        Evt_dis(ActionEvent::UPDATE_CURSOR, &frameIdx);
    }

    virtual void mouseMoveEvent(QMouseEvent *mouseEvent) override {
        if (isPress) {
            updateCursor();
        }
    }

    virtual void mouseReleaseEvent(QMouseEvent *mouseEvent) override {
        isPress = false;

    }
};


#endif //SEQTRUAN_TIMESTAMPBAR_H
