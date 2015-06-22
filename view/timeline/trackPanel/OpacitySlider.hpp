#pragma once
//
// Created by manoyuria on 2015/6/22.
//

#ifndef SEQTRUAN_OPACITYSLIDER_HPP
#define SEQTRUAN_OPACITYSLIDER_HPP

#endif //SEQTRUAN_OPACITYSLIDER_HPP

#include "view/UI.hpp"

class OpacitySlider : QWidget {
public:
    OpacitySlider(QWidget *parent) : QWidget(parent) { };
protected:
    virtual void paintEvent(QPaintEvent *e) override {
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    };
};