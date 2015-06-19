//
// Created by manoyuria on 2015/6/19.
//

#include "OverWidget.h"

OverWidget::OverWidget(QWidget *parent) : QWidget(parent) {

}

void OverWidget::paintEvent(QPaintEvent *event) {
    dis(paintEvent_);
}
