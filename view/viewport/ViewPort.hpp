//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_VIEWPORT_H
#define SEQTRUAN_VIEWPORT_H

#endif //SEQTRUAN_VIEWPORT_H

#include "view/UI.hpp"
#include "Transport.hpp"
#include "ComCanvas.hpp"

class ViewPort : public QWidget {
public:
    ViewPort(QWidget *parent = 0) : QWidget(parent) {
        resize(1280, 500);
        canvas = new ComCanvas(this);

        _transport = new Transport(this);
        Evt_add(SequencePlaybackEvent::RENDER_FRAME, onRenderFrame)
    };

private:
    ComCanvas *canvas;
    QPixmap *thumbPixmap = nullptr;
    QImage *img = nullptr;

    void onRenderCanvas() {
        QPainter p;
        p.drawImage(0, 0, *img);
    }

protected:
    virtual void resizeEvent(QResizeEvent *qResizeEvent) override {
        _setY(_transport, height() - _transport->height());
    }

    void onRenderFrame(SequencePlaybackEvent *e) {
        img = App()._().trackModel->getRenderFrame(e->frameIdx);
        if (img)
            canvas->setImage(img);
    }

    Transport *_transport;
};

