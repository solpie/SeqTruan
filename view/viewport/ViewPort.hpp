//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_VIEWPORT_H
#define SEQTRUAN_VIEWPORT_H

#endif //SEQTRUAN_VIEWPORT_H

#include "view/UI.hpp"
#include "Transport.hpp"

class ViewPort : public QWidget {
Q_OBJECT
public:
    ViewPort(QWidget *parent = 0): QWidget(parent) {
        resize(1280, 500);
        _transport = new Transport(this);
    };

private:
    Transport *_transport;
};