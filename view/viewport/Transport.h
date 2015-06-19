#pragma once
//
// Created by manoyuria on 2015/6/19.
//

#ifndef SEQTRUAN_TRANSPORT_H
#define SEQTRUAN_TRANSPORT_H

#include "view/UI.h"
class Transport :public QWidget{
public:
    Transport(QWidget *parent);

private:
    void togglePlay();

    void onFrameRateChanged();
};


#endif //SEQTRUAN_TRANSPORT_H
