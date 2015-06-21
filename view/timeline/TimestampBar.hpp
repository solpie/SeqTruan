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
        setStyleSheet("background:#3e3e3e");
    }


protected:
    virtual void paintEvent(QPaintEvent *qPaintEvent) override {
        QPainter p(this);
        QPen pen(QColor(0x343434));
        p.setPen(pen);
        int fw = App()._().trackModel->frameWidth;
        int fr = App()._().trackModel->sequencePlayback->getFramerate();
        for (int i = 0; i < this->width(); i += fw) {
            p.drawLine(i, 15, i, this->height());
        }
        for (int i = 0; i < this->width(); i += fw * fr) {
            p.drawLine(i, 5, i, this->height());
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
