//
// Created by toramisu on 2015/6/16.
//

#include "SeqTruanWin.h"

SeqTruanWin::SeqTruanWin(QWidget *parent) {
    resize(1440, 1056);

    QSplitter *vSplitter = new QSplitter(Qt::Vertical, this);
    vSplitter->resize(width(), height());
    vSplitter->setOpaqueResize(false);
    ViewPort *viewPort = new ViewPort(vSplitter);
    _timeline = new Timeline(vSplitter);

    setStyleSheet("background:#484848");
    qDebug() << "inited SeqTruanWin";
}


