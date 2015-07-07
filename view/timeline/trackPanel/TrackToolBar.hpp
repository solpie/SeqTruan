//
// Created by toramisu on 2015/6/16.
//
#pragma once

#include "view/UI.hpp"
//#include <model/App.h>

#ifndef SEQTRUAN_TRACKTOOLBAR_H
#define SEQTRUAN_TRACKTOOLBAR_H

#endif //SEQTRUAN_TRACKTOOLBAR_H

class TrackToolBar : public QWidget {
public:
    TrackToolBar(QWidget *parent = 0) : QWidget(parent) {
        resize(250, 25);
        newTrackButton = new QPushButton("new Track", this);

//        OverWidget *dragButton = new OverWidget(this);
//        UI::setWidth(dragButton, 20);
//        UI::setHeight(dragButton, 20);
//        UI::setX(dragButton, width() - 20);

        zoomButton = new QPushButton("Z", this);
        UI::setWidth(zoomButton, 20);
        UI::setHeight(zoomButton, 20);
        UI::setX(zoomButton, width() - 20);
//        zoomButton->setCheckable(true);
        zoomButton->connect(zoomButton, zoomButton->pressed, [this]() { onPressZoomButton(); });
        zoomButton->connect(zoomButton, zoomButton->released, [this]() { onReleaseZoomButton(); });

//        zoomButton->setAttribute(Qt::WA_TransparentForMouseEvents, true);


//    QObject::connect(newTrackButton, &QPushButton::clicked, someFunction);
//    newTrackButton->mouseMoveEvent
//    TrackModel *t = TrackModel::_();
//    t->newTrack();
//        connect(newTrackButton, &QPushButton::clicked, []{
////        printf("click me");
//            App()._().trackModel->newTrack("new track","");
//        });
//    this.pressed.connect(someFunction);
//    this->onClkNewTrackBtn();
    }

    void onClkNewTrackBtn() { };

    void onVScrollBar() { };

private:
    QPushButton *zoomButton;
    bool isPressZoomButton = false;
    int _lastX = 0;

    void onPressZoomButton() {
        isPressZoomButton = true;
        _lastX = _localPos.x();
    }

    void onReleaseZoomButton() {
//        bool isInRect = UI::isIn(this);
//        if (isInRect) {
//            isPressZoomButton = false;
//            qDebug() << this << "onReleaseZoomButton" << isPressZoomButton;
//        }
//        qDebug() << this << "onReleaseZoomButton Buttons" << QApplication::mouseButtons();
        bool isPressLMB = (QApplication::mouseButtons() == Qt::LeftButton);
        if (!isPressLMB) {
            isPressZoomButton = false;
//            _app.trackModel->setZoomLevel(2);
            qDebug() << this << "onReleaseZoomButton" << isPressZoomButton;
        }
    }

    QPushButton *newTrackButton;


protected:
    virtual void mouseMoveEvent(QMouseEvent *mouseEvent) override {
        if (isPressZoomButton) {
            int mx = _localPos.x();
            float dx = mx - _lastX;
            if (dx > -320 && dx < 320) {
                //320 40
                float raito = (dx) / 320 + _app.trackModel->getZoomRaito();
                if (raito < 0.025) {
                    raito = 0.025;
                }
                else if (raito > 1) {
                    raito = 1;
                }
                _app.trackModel->setZoomLevel(raito);
            }
            _lastX = mx;
            qDebug() << this << "mouseMoveEvent" << isPressZoomButton << dx;
        }
    };

    virtual void mouseReleaseEvent(QMouseEvent *mouseEvent) override {
        if (isPressZoomButton) {
            isPressZoomButton = false;
        }
        qDebug() << this << "mouseReleaseEvent" << isPressZoomButton;
    };
};
