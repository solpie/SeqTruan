//
// Created by toramisu on 2015/6/16.
//
#include "ViewPort.h"

ViewPort::ViewPort(QWidget *parent) : QWidget(parent) {
    resize(1280, 500);
    _transport = new Transport(this);
};