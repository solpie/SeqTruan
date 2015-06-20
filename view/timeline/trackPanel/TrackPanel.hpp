#pragma once
//
// Created by manoyuria on 2015/6/20.
//

#ifndef SEQTRUAN_TRACKPANEL_H
#define SEQTRUAN_TRACKPANEL_H

#include "view/UI.hpp"
class TrackPanel :public QWidget{
public:
    TrackPanel(QWidget *parent=0):QWidget(parent)
    {
        resize(TIMELINE_TRACK_PANEL_DEF_WIDTH, TIMELINE_TRACK_DEF_HEIGHT);
        opacitySlider = new QSlider(Qt::Horizontal, this);
        opacitySlider->move(200, 37);
        opacitySlider->resize(80, 15);
        opacitySlider->setRange(0, 100);
        opacitySlider->setValue(100);
        UI::setQss(opacitySlider, ":/qss_slider");
//    valueChanged()	Emitted when the slider's value has changed. The tracking() determines whether this signal is emitted during user interaction.
//    sliderPressed()	Emitted when the user starts to drag the slider.
//            sliderMoved()	Emitted when the user drags the slider.
//            sliderReleased()
//    self.opacitySlider.mousePressEvent = self.onPressSlider
//    self.opacitySlider.mouseMoveEvent = self.onMoveSlider
        connect(opacitySlider, QSlider::valueChanged, [this](int pos){this->onOpacityChanged(pos);});
//    connect(opacitySlider, QSlider::sliderMoved, [this](int pos) { this->onOpacityChanged(pos); });
        trackNameLabel = new QLabel(this);
        trackNameLabel->move(5, 5);

        visibleCheck = new QCheckBox(this);
        visibleCheck->move(200, 5);
    }
    void setTrackName(QString tname){
        trackNameLabel->setText(tname);
    };

private:
    QLabel *trackNameLabel;
    QCheckBox *visibleCheck;
    void onOpacityChanged(int newPos){
        qDebug() << this << this->opacitySlider->value();
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
            if (sliderPosUnderMouse != newPos) {
                opacitySlider->setValue(sliderPosUnderMouse);
                return;
            }
        }
    };
    void onPressSlider();
    QSlider *opacitySlider;

};


#endif //SEQTRUAN_TRACKPANEL_H
