#pragma once
//
// Created by manoyuria on 2015/6/20.
//

#ifndef SEQTRUAN_TRACKPANEL_H
#define SEQTRUAN_TRACKPANEL_H

#include <events/PopupEvent.hpp>
#include "view/UI.hpp"
#include "OpacitySlider.hpp"

class TrackPanel : public QWidget {
public:
    TrackPanel(QWidget *parent = 0) : QWidget(parent) {
        resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, TIMELINE_TRACK_DEF_HEIGHT);
        opacitySlider = new QSlider(this);
        opacitySlider->setOrientation(Qt::Horizontal);
        opacitySlider->move(200, 37);
        opacitySlider->resize(80, 15);
        opacitySlider->setRange(0, 100);
        opacitySlider->setValue(100);
        UI::setQss(opacitySlider, ":/qss_slider", "opacity");
//    valueChanged()	Emitted when the slider's value has changed. The tracking() determines whether this signal is emitted during user interaction.
//    sliderPressed()	Emitted when the user starts to drag the slider.
//            sliderMoved()	Emitted when the user drags the slider.
//            sliderReleased()
//        over(opacitySlider, mousePressEvent_, onPressSlider);
//        over(opacitySlider, mouseMoveEvent_, onMoveSlider);
        connect(opacitySlider, opacitySlider->valueChanged, [this]() { this->onOpacityChanged(); });
//        connect(opacitySlider, QSlider::sliderMoved, [this]() { this->onOpacityChanged(); });
//        opacitySlider->setMouseTracking(true);
        trackNameLabel = new QLabel(this);
        trackNameLabel->move(5, 5);

        visibleCheck = new QCheckBox(this);
        visibleCheck->setCheckState(Qt::Checked);
        visibleCheck->move(200, 5);
        connect(visibleCheck, visibleCheck->stateChanged, [this](int state) {
            _trackInfo->visible = bool(state);
            _app.trackModel->sequencePlayback->update();

            qDebug() << this << "stateChanged" << state << _trackInfo->visible;
        });


        setContextMenuPolicy(Qt::CustomContextMenu);
        connect(this, this->customContextMenuRequested, [=](const QPoint &q) {
            qDebug() << this << "menu" << q;
            PopupEvent *e = new PopupEvent();
            e->posX = q.x();
            e->posY = q.y();
            e->add("itme1", [] { });
            e->add("itme2", [] { });
            Evt_dis(ActionEvent::POPUP_MENU, e)
        });
    }


    void setTrackInfo(TrackInfo *trackInfo) {
        _trackInfo = trackInfo;
        trackNameLabel->setText(_trackInfo->name);
    }

private:
    TrackInfo *_trackInfo;
    QSlider *opacitySlider;
//    OpacitySlider *opacitySlider;
    QLabel *trackNameLabel;
    QCheckBox *visibleCheck;

    void onOpacityChanged(int newPos = 0) {
        qDebug() << this << "onOpacityChanged" << this->opacitySlider->value();
        // Make slider to follow the mouse directly and not by pageStep steps
        Qt::MouseButtons btns = QApplication::mouseButtons();
        QPoint localMousePos = opacitySlider->mapFromGlobal(QCursor::pos());
        bool clickOnSlider = (btns & Qt::LeftButton) &&
                             (localMousePos.x() >= 0 && localMousePos.y() >= 0 &&
                              localMousePos.x() < opacitySlider->size().width() &&
                              localMousePos.y() < opacitySlider->size().height());
        if (clickOnSlider) {
            // Attention! The following works only for Horizontal, Left-to-right sliders
            float posRatio = localMousePos.x() / (float) opacitySlider->size().width();
            int sliderRange = opacitySlider->maximum() - opacitySlider->minimum();
            int sliderPosUnderMouse = opacitySlider->minimum() + sliderRange * posRatio;
//            if (sliderPosUnderMouse != newPos) {
            opacitySlider->setValue(sliderPosUnderMouse);
//            return;
//            }
        }
        _trackInfo->setOpacity(opacitySlider->value() / double(100));
        _app.trackModel->sequencePlayback->update();
//        opacitySlider->setValue(
//                QStyle::sliderValueFromPosition(opacitySlider->minimum(), opacitySlider->maximum(), localMousePos.x(),
//                                                opacitySlider->width()));
    };

    void onMoveSlider(QMouseEvent *e) {
        if (e->buttons() == Qt::LeftButton)
            opacitySlider->setValue(
                    QStyle::sliderValueFromPosition(opacitySlider->minimum(), opacitySlider->maximum(), e->x(),
                                                    opacitySlider->width()));
    }

    void onPressSlider(QMouseEvent *e) {
        if (e->buttons() == Qt::LeftButton)
            opacitySlider->setValue(
                    QStyle::sliderValueFromPosition(opacitySlider->minimum(), opacitySlider->maximum(), e->x(),
                                                    opacitySlider->width()));
    }

};


#endif //SEQTRUAN_TRACKPANEL_H
