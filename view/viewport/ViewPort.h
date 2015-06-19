//
// Created by toramisu on 2015/6/16.
//
#pragma once
#ifndef SEQTRUAN_VIEWPORT_H
#define SEQTRUAN_VIEWPORT_H

#endif //SEQTRUAN_VIEWPORT_H

#include "view/UI.h"
#include "Transport.h"

class ViewPort : public QWidget {
Q_OBJECT
public:
    ViewPort(QWidget *parent = 0);

private:
    Transport *_transport;
};